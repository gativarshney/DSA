// GFG Problem
int find(int par[], int x) {
    if(par[x] == x) return x;
    return par[x] = find(par, par[x]);  
}

void unionSet(int par[], int x, int z) {
    par[find(par, x)] = find(par, z);
}
// In this approach, we are using a simple union-find (or disjoint set) data structure without any optimizations like union by rank or union by size. The find function uses path compression to optimize the find operation, which helps to flatten the structure of the tree and speed up future operations. The unionSet function simply attaches one tree to another without considering the rank or size of the trees, which can lead to unbalanced trees and degrade the time complexity of future find operations.