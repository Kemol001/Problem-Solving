// Ahmed and Omar love playing Scrabble. They made a new game using alphabet tiles.
// Omar wrote a string using the tiles and gave a set of pairs of integers (i,j) to Ahmed.
// Pair “i, j” (0 based indexing) means that Ahmed can swap the i’th and j’th tile in the string any number
// of times. He then asks Ahmed to give the lexicographically smallest string that can be produced by doing any
// number of swaps on the original string.
// Input
// The input consists of multiple test cases. The first line contains T (1 <= T <= 10), the number of test cases.
// The first line of each test case contains the initial string S.The length of string is len (1 <= len <= 100000).
// The next line contains the number of pairs M (1 <= M <= 100000).
// The following M lines contain pairs i j that means i-th character can be swapped with j-th character.
// Note - i and j can be same. Additionally, the same i, j pair can occur twice.
// Output
// For each testcase output the lexicographically smallest string that can be made from the initial string.

#include<bits/stdc++.h>
using namespace std;

const int A = 1e5+5;
int B, C;
string D;
vector<int> E[A];
int F[A];
bool G[A];
char H[A];
int I;

void J(int K){
    F[++I] = K;
    H[I] = D[K];
    G[K] = true;
    for(int L : E[K])
        if(!G[L])
            J(L);
}

int main(){
    int M; 
    cin >> M;
    while(M--){
        cin >> D;
        for(int N = 0; N < D.length(); N++)
            E[N].clear();

        cin >> C;
        int O, P;
        for(int Q = 0; Q < C; Q++){
            cin >> O >> P;
            E[O].push_back(P);
            E[P].push_back(O);
        }

        memset(G, 0, sizeof(G));
        for(int R = 0; R < D.length(); R++){
            if(!G[R]){
                I = 0;
                J(R);
                sort(F+1, F+I+1);
                sort(H+1, H+I+1);
                for(int S = 1; S <= I; ++S) 
                    D[F[S]] = H[S];
            }
        }
        cout << D << endl;
    }
}