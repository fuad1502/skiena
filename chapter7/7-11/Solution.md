We could perform a BFS and do an evaluation on process_vertex_late as follows:
```
if edge[v] == null
    result[v] = number[v] 
y_1 = edge[v]->y
y_2 = edge[v]->next->y
result[v] = operate(result[y_1], result[y_2], operation[v])
```
