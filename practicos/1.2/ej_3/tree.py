import graphviz
# from graphviz import Digraph

def draw_tree():
#   Grafo
    dot = graphviz.Digraph()

#   Nodos
    dot.node("quick_sort(a)")
    dot.node("quick_sort_rec(a, 1, 7)")
    dot.node("quick_sort_rec(a, 1, 4)")
    dot.node("quick_sort_rec(a, 5, 7)")
    dot.node("quick_sort_rec(a, 1, 2)")
    dot.node("quick_sort_rec(a, 4, 4)")
    dot.node("quick_sort_rec(a, 1, 1)")
    dot.node("quick_sort_rec(a, 3, 2)")
    dot.node("quick_sort_rec(a, 5, 4)")
    dot.node("quick_sort_rec(a, 6, 7)")
    dot.node("quick_sort_rec(a, 6, 5)")
    dot.node("quick_sort_rec(a, 7, 7)")

#  Aristas
    dot.edge("quick_sort(a)", "quick_sort_rec(a, 1, 7)")
    dot.edge("quick_sort_rec(a, 1, 7)", "quick_sort_rec(a, 1, 4)")
    dot.edge("quick_sort_rec(a, 1, 7)", "quick_sort_rec(a, 5, 7)")
    dot.edge("quick_sort_rec(a, 1, 4)", "quick_sort_rec(a, 1, 2)")
    dot.edge("quick_sort_rec(a, 1, 4)", "quick_sort_rec(a, 4, 4)")
    dot.edge("quick_sort_rec(a, 1, 2)", "quick_sort_rec(a, 1, 1)")
    dot.edge("quick_sort_rec(a, 1, 2)", "quick_sort_rec(a, 3, 2)")
    dot.edge("quick_sort_rec(a, 5, 7)", "quick_sort_rec(a, 5, 4)")
    dot.edge("quick_sort_rec(a, 5, 7)", "quick_sort_rec(a, 6, 7)")
    dot.edge("quick_sort_rec(a, 6, 7)", "quick_sort_rec(a, 6, 5)")
    dot.edge("quick_sort_rec(a, 6, 7)", "quick_sort_rec(a, 7, 7)")

#  Renderizar el grafo en un archivo SVG y abrirlo 
#   dot.render("quick_sort_tree.gv", view=True)

# Renderizar el grafo en un archivo PNG
    dot.render("quick_sort_tree", format="png")

draw_tree()
