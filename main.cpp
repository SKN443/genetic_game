#include <iostream>
#include <bitset>
#include <cstdio>
#include "Evol.h"
#include "Gene.h"
#include "cell.h"

using namespace std;

const int numgene = 8640;

vector <pair<int, int> > firstgen;
int max8640=0;
int cur_combine[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 369, 172};
pair<int, int> adj[] = {{1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, {0, -1}};
CellData listcase;
Gen cur;
Evol evoluate;
int cnt=0;
char res[16][16];

const int patterntop2[] = {
        448,
        8,
        448,
        457,
        62,
        9,
        22,
        67,
        274,
        36,
        2,
        6,
        4,
        256,
        4,
        335
    };

void Cal() {
    cnt++;
    cerr<<cnt <<'\n';
    cur.init(firstgen);
    int sumliving = 0;
    for(int i=0; i<numgene; i++) {
        sumliving += cur.gettotal();
        evoluate.init();
        vector<pair<int, int> > curliving = cur.getvec();
        for(const auto& it : curliving) {
            for(const auto& adjcell : adj) {
                evoluate.update({it.first+adjcell.first, it.second+adjcell.second});
            }
        }

        if(i==1000 && sumliving<450000) {
            cout <<sumliving <<'\n';
            return;
        }
        else if(i==4000 && sumliving>5500000) {
            freopen("cur.txt", "a", stdout);

            printf("%d\n", sumliving);
            for(const int& it : cur_combine)
                printf("%d, ", it);
            printf("\n");
            bitset<9> s;
            for(int k=0; k<16; k++) {
                s = listcase.cellData[cur_combine[k]]^patterntop2[k];
                for(int j=8; j>=0; j--) {
                    res[2-j/3+k/4*3][k%4*3+2-(j%3)]=(s[j] ? '1' : '0');
                }
            }
            for(int k=0; k<12; k++)
                for(int j=0; j<12; j++)
                    printf("%c", res[k][j]);

            printf("\n");
            fclose(stdout);
            return;
        }
        else if (i==4000) return;

        curliving = evoluate.Listliving(cur);
        cur.init(curliving);
    }
}

void initcell(int n, int x, int y) {
    bitset<9> s(n);
    for(int i=8; i>=0; i--) {
        if (s[i]==1) {
            firstgen.push_back(pair<int, int> (9000+x*3+(8-i)/3, 9000+y*3+(8-i)%3));
        }
    }
}

void clearcell(int n) {
    bitset<9> s(n);
    for(int i=0; i<s.count(); i++) {
        firstgen.pop_back();
    }
}

void Try(int i) {
    if(i==16) {
        Cal();
        return;
    }
    int j=cur_combine[i];
    while(j<512) {
        initcell(listcase.cellData[j]^patterntop2[i], i/4, i%4);
        cur_combine[i]=j;
        Try(i+1);
        clearcell(listcase.cellData[j]^patterntop2[i]);
        j++;
    }
    cur_combine[i] = 0;
}

int main() {
    Try(0);
    return 0;
}
