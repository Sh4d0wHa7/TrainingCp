#include <bits/stdc++.h>
#define TAM 1005
using namespace std;

char matriz[TAM][TAM];
int movimientos[TAM][TAM];
bool visitados[TAM][TAM];

struct nodo{
    int fila,colu;
    int pasos;

    bool operator < (const nodo & a) const {
        return a.pasos < pasos;
    }
};

bool dentro(int fila, int colu, int n, int m){
    return fila<n && fila>=1 && colu<m && colu>=1;
}

priority_queue <nodo> cola;

int main()
{
    int n,m,a,b,filaFin,coluFin;
    cin>>n>>m>>a>>b;
    cin>>filaFin>>coluFin;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>matriz[i][j];
            if (matriz[i][j]=='#')
                visitados[i][j]=1;
        }
    }

    nodo padre;
    padre.fila=a;
    padre.colu=b;
    cola.push(padre);

    while (!cola.empty()){
        padre= cola.top();
        padre.pasos++;
        cola.pop();
        if (padre.fila==filaFin && padre.colu==coluFin){
                cout<< padre.pasos;
                return 0;
        }

        if (visitados[padre.fila][padre.colu]==1)
            continue;

        visitados[padre.fila][padre.colu]=1;


        nodo hijo=padre;
        hijo.fila=padre.fila-1;
        if (!visitados[hijo.fila][hijo.colu] && dentro(hijo.fila,hijo.colu,n,m))
            cola.push(hijo);

        hijo.fila=padre.fila+1;
        if (!visitados[hijo.fila][hijo.colu] && dentro(hijo.fila,hijo.colu,n,m))
            cola.push(hijo);

        hijo=padre;
        hijo.colu=padre.colu+1;
        if (!visitados[hijo.fila][hijo.colu] && dentro(hijo.fila,hijo.colu,n,m))
            cola.push(hijo);

        hijo.colu=padre.colu-1;
        if (!visitados[hijo.fila][hijo.colu] && dentro(hijo.fila,hijo.colu,n,m))
            cola.push(hijo);
    }

    cout<< "No hay camino papu";
    return 0;
}
