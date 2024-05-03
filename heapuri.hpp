#include<iostream>
#include<fstream>
using namespace std;
class Binary{
    int n,arr[100];
public:
    int getN(){return n;}
    int getA(int i){return arr[i];}
    void setN(int N){n=N;}
    void setA(int i,int val){arr[i]=val;}
    friend istream &operator>>(istream &in, Binary &B){
        in>>B.n;
        for(int i=0;i<B.n;i++){
            in>>B.arr[i];
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, Binary &B){
        out<<B.n<<"\n";
        for(int i=0;i<B.n;i++){
            out<<B.arr[i]<<" ";
        }
        out<<"\n";
        return out;
    }
    int parinte(int i){
        return (i-1)/2;
    }
    int fiu_stang(int i){
        return 2*i+1;
    }
    int fiu_drept(int i){
        return 2*i+2;
    }
    int cautare_minim(){
        return arr[0];
    }
    void inserare(int ins){
        n++;
        arr[n-1]=ins;
        int poz=n-1;
        while(arr[parinte(poz)]>arr[poz]){
            swap(arr[poz],arr[parinte(poz)]);
            poz=parinte(poz);
        }
    }
    int stergere_min(){
        int minimum = arr[0];
        swap(arr[0],arr[n-1]);
        n--;
        int s=0;
        while(true){
            if(fiu_stang(s)>=n || arr[s]<arr[fiu_stang(s)]){
                if(fiu_drept(s)>=n || arr[s]<arr[fiu_drept(s)]){
                    break;
                }
            }
            if(arr[fiu_stang(s)]<arr[fiu_drept(s)]){
                swap(arr[s],arr[fiu_stang(s)]);
                s=fiu_stang(s);
            }
            else if(arr[fiu_stang(s)]>=arr[fiu_drept(s)]){
                swap(arr[s],arr[fiu_drept(s)]);
                s=fiu_drept(s);
            }
        }
        return minimum;
    }
    void update(int i,int val){
        arr[i]=val;
        int s=i;
        while(arr[s]<arr[parinte(s)]){
            swap(arr[s],arr[parinte(s)]);
            s=parinte(s);
        }
        while(true){
            if(fiu_stang(s)>=n || arr[s]<arr[fiu_stang(s)]){
                if(fiu_drept(s)>=n || arr[s]<arr[fiu_drept(s)]){
                    break;
                }
            }
            if(arr[fiu_stang(s)]<arr[fiu_drept(s)]){
                swap(arr[s],arr[fiu_stang(s)]);
                s=fiu_stang(s);
            }
            else if(arr[fiu_stang(s)]>=arr[fiu_drept(s)]){
                swap(arr[s],arr[fiu_drept(s)]);
                s=fiu_drept(s);
            }
        }
    }
    bool cautare(int start, int val){
        if(arr[start]==val) return true;
        if(arr[start]<val){
            bool st = false, dr = false;
            if(fiu_stang(start)<n) st = cautare(fiu_stang(start),val);
            if(fiu_drept(start)<n) dr = cautare(fiu_drept(start),val);
            return st||dr;
        }
        return false;
    }
};
class StrictFibo{
    int nr_heap,marimi[10],heaps[10][100],lim_deg,poz_min=0;
public:
    friend istream &operator>>(istream &in, StrictFibo &S){
        in>>S.nr_heap>>S.lim_deg;
        for(int i=0;i<S.nr_heap;i++){
            in>>S.marimi[i];
            for(int j=0;j<S.marimi[i];j++){
                in>>S.heaps[i][j];
            }
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, StrictFibo &S){
        out<<S.nr_heap<<"\n";
        for(int i=0;i<S.nr_heap;i++){
            for(int j=0;j<S.marimi[i];j++){
                out<<S.heaps[i][j]<<" ";
            }
            out<<"\n";
        }
        return out;
    }
    int parinte(int i){
        return (i-1)/2;
    }
    int fiu_stang(int i){
        return 2*i+1;
    }
    int fiu_drept(int i){
        return 2*i+2;
    }
    int cautare_minim(){
        return heaps[0][0];
    }
    void inserare(int ins){
        nr_heap++;
        marimi[nr_heap-1]=1;
        heaps[nr_heap-1][0]=ins;
        if(ins<heaps[poz_min][0]) poz_min=nr_heap-1;
    }
    int stergere_min(){
        int minimum = heaps[poz_min][0];
        swap(heaps[poz_min][0],heaps[0][marimi[poz_min]-1]);
        marimi[poz_min]--;
        int s=0;
        while(true){
            if(fiu_stang(s)>=nr_heap || heaps[0][s]<heaps[0][fiu_stang(s)]){
                if(fiu_drept(s)>=nr_heap || heaps[0][s]<heaps[0][fiu_drept(s)]){
                    break;
                }
            }
            if(heaps[0][fiu_stang(s)]<heaps[0][fiu_drept(s)]){
                swap(heaps[0][s],heaps[0][fiu_stang(s)]);
                s=fiu_stang(s);
            }
            else if(heaps[0][fiu_stang(s)]>=heaps[0][fiu_drept(s)]){
                swap(heaps[0][s],heaps[0][fiu_drept(s)]);
                s=fiu_drept(s);
            }
        }
        return minimum;
    }
    StrictFibo reuniune(StrictFibo S1, StrictFibo S2){
        StrictFibo S3;
        S1.nr_heap += S2.nr_heap;
        for(int i=0;i<S1.nr_heap;i++){
            S3.marimi[i] = S1.marimi[i];
            for(int j=0;j<S1.marimi[i];j++){
                S3.heaps[i][j] = S1.heaps[i][j];
            }
        }
        for(int i=S1.nr_heap;i<S3.nr_heap;i++){
            S3.marimi[i] = S2.marimi[i];
            for(int j=0;j<S2.marimi[i];j++){
                S3.heaps[i][j] = S2.heaps[i][j];
            }
        }
        S1=S3;
        return S1;
    }
};
