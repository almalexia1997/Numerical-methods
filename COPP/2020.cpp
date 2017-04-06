#include <iostream>
#include <vector>

using namespace std;

int Replay(int n, int x, vector<int>a)
{
    int ch=0;
    for(int i=0; i<n; ++i)
    {
        if(a[i]==a[x])
            ch++;
        //cout<<a[i]<<" *"<<ch<<endl;
    }

    return ch;
}

int main()
{
    int n;
    cin>>n;
    vector<int>a( n );
    int c=0;
    int f=0;
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
    }
    int max=0;
    for(int i=0; i<n; ++i)
    {
        c=Replay(n,i,a);
        if(c>max)
        {
            max=c;
            f=a[i];
        }
    }
    cout<<f<<" "<<max<<endl;
    return 0;
}
