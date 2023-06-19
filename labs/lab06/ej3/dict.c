#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

/*
 * @brief: Checks if all the elements of the right subtree are 
 * greater than the root of the tree. 
 *        
 * @param tree: The subtree to check.
 * @param e: The root of the tree of type abb_elem.
 * @return: True if all the elements of the right subtree are greater than
 * */

static bool 
isSubtreeRightGreater(dict_t tree, key_t e)
{   
    bool res = true;
    if(tree != NULL) 
    {
        res = key_less(e, tree->key) && 
              isSubtreeRightGreater(tree->right, e) &&
              isSubtreeRightGreater(tree->left, e);
    }

    return(res);
}

/*
 * @brief: Checks if all the elements of the left subtree are 
 * less than the root of the tree. 
 *
 * @param tree: The tree to check.
 * @param e: The root of the tree. 
 * @return: True if all the elements of the left subtree are less than
 *
 * */

static bool 
isSubtreeLeftLess(dict_t tree, key_t e)
{   
    bool res = true;
    if(tree != NULL) 
    {
        res = key_less(tree->key, e) &&
              isSubtreeLeftLess(tree->left, e) &&
              isSubtreeLeftLess(tree->right, e);
    }

    return(res);
}

static bool
invrep(dict_t tree)
{
    bool res = true;
    if(tree==NULL)
    {
        res = true;
    }
    else
    {    
        res = isSubtreeRightGreater(tree->right, tree->key) &&
              isSubtreeLeftLess(tree->left, tree->key) &&
              invrep(tree->right) && invrep(tree->left);
    }

    return(res);
}

 /*
 * @brief: Creates a leaf of the abb.
 * @param: e: The element of the leaf.
 * @return: The leaf.
 *  */

static dict_t 
mk_leaf(key_t key, value_t def) 
{   
    dict_t tree = NULL; 
    tree = malloc(sizeof(struct _node_t));
    assert(tree != NULL);
    tree->key = key;
    tree->value = def;
    tree->left = NULL; 
    tree->right = NULL;
    
    return(tree);
}

/*
 * @brief: destroys a leaf of the dictionary.
 * @return: NULL
 *
 * */ 

static dict_t
rm_leaf(dict_t tree)
{
    assert(tree != NULL);
    tree->key = key_destroy(tree->key);
    tree->value = value_destroy(tree->value);
    tree->left = NULL;
    tree->right = NULL;
    free(tree);
    tree = NULL;

    return(tree);
}

/*
 * @brief: compute the maximum element of the tree.
 * @param: tree: The tree.
 * @return: The maximum element of the tree.
 * @pre: The tree is not empty.
 * @post: The maximum element is in the tree.
 * */ 

static key_t
dict_max(dict_t tree) 
{
    assert(invrep(tree) && dict_length(tree) > 0u);
    key_t max_e;
    if(tree->right == NULL)
    {
        max_e = tree->key;
    }
    else
    {
        max_e = dict_max(tree->right);
    }
    assert(invrep(tree) && dict_exists(tree, max_e));
    
    return(max_e);
}

/*
 * @brief: removes the maximum element of the tree.
 * @param: tree: The tree. 
 * @return: The tree without the maximum element. 
 * 
 * @pre: The tree is not empty.
 *
 *  */

static dict_t 
remove_max(dict_t tree)
{
    if(tree != NULL)
    {
        if(tree->right == NULL)
        {   
            dict_t ref = tree->left;
            rm_leaf(tree);
            return(ref);
        }
        else 
        {
            tree->right = remove_max(tree->right);
        }
    }

    return(tree);
}


dict_t
dict_remove(dict_t tree, key_t e)
{
    assert(invrep(tree));
    
    if(tree != NULL )
    {
        if(key_less(e, tree->key))
        {
            tree->left = dict_remove(tree->left, e);
        }
        else if(key_less(tree->key, e))
        {
            tree->right = dict_remove(tree->right, e);
        }
        else 
        {
            if(tree->left == NULL)
            {
                dict_t tp = tree->right;
                rm_leaf(tree);
                tree = tp;
                tp = NULL;
            }
            else 
            {
                tree->key = dict_max(tree->left);
                tree->value = dict_search(tree->left, tree->key);
                tree->left = remove_max(tree->left);
            }
        }   
    }
    assert(invrep(tree)); // && !dict_exists(tree, e));

    return(tree);
}
 



dict_t 
dict_empty(void) 
{
    dict_t dict = NULL;
    assert(invrep(dict));

    return(dict);
}

dict_t
dict_add(dict_t dict, key_t word, value_t def)
{
    assert(invrep(dict));
    if(dict==NULL)
    {
        dict = mk_leaf(word, def);
    }
    else 
    {
        if(key_eq(word, dict->key))
        {
            dict->value = def;
        }
        else if(key_less(word, dict->key))
        {
            dict->left = dict_add(dict->left, word, def);
        }
        else if(key_less(dict->key, word))
        {
            dict->right = dict_add(dict->right, word, def);
        }
    } 
    assert(invrep(dict) && value_eq(def, dict_search(dict, word)));

    return(dict);
}


value_t 
dict_search(dict_t dict, key_t word)
{
    assert(invrep(dict));
    key_t def = dict == NULL                 ? NULL
              : string_eq(word, dict->key)   ? dict->value
              : string_less(word, dict->key) ? dict_search(dict->left, word)
              : /* otherwise */                dict_search(dict->right, word);

    return(def);
}

bool 
dict_exists(dict_t dict, key_t word)
{
    return(dict_search(dict, word) != NULL);
}


/*
value_t
dict_search(dict_t dict, key_t word)
{
    assert(invrep(dict));
    value_t def = NULL;
    if(dict_exists(dict, word))
    {
        if(key_eq(word, dict->key))
        {
            def = dict->value;
        }
        else if(key_less(word, dict->key))
        {
            def = dict_search(dict->left, word);
        }
        else
        {
            def = dict_search(dict->right, word);
        }
    }
    
    return(def);
}
*/ 

/*
bool 
dict_exists(dict_t dict, key_t word) 
{
    assert(invrep(dict));
    bool exists = false;
    exists = (dict!=NULL) && ((key_eq(word, dict->key)) || 
             (key_less(dict->key, word) && dict_exists(dict->right, word)) ||
             (key_less(word, dict->key) && dict_exists(dict->left, word)));

    return(exists);
}
*/ 

unsigned int
dict_length(dict_t dict)
{
    assert(invrep(dict));
    unsigned int length = 0u;
    if(dict != NULL)
    {
        length = 1u + dict_length(dict->right) 
                    + dict_length(dict->left);
    }

    return(length);
}

dict_t
dict_remove_all(dict_t dict)
{
    assert(invrep(dict));
    if(dict != NULL) 
    {
        dict->key = key_destroy(dict->key);
        dict->value = value_destroy(dict->value);
        dict->left = dict_destroy(dict->left);
        dict->right = dict_destroy(dict->right);
        free(dict); 
        dict = NULL;
    }
    assert(invrep(dict) && dict_length(dict) == 0u);
    
    return(dict);
}

void 
dict_dump(dict_t dict, FILE *file)
{   
    if(dict != NULL)
    {
        dict_dump(dict->left, file);
        key_dump(dict->key, file);
        value_dump(dict->value, file);
        dict_dump(dict->right, file);
    }
}

dict_t
dict_destroy(dict_t dict)
{
    return(dict_remove_all(dict));
}
