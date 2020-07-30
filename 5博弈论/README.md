# 博弈论（巴什博奕，威佐夫博弈，尼姆博弈，斐波那契博弈）

一.  巴什博奕（Bash Game）：

  A和B一块报数，每人每次报最少1个，最多报4个，看谁先报到30。这应该是最古老的关于巴什博奕的游戏了吧。

其实如果知道原理，这游戏一点运气成分都没有，只和先手后手有关，比如第一次报数，A报k个数，那么B报5-k个数，那么B报数之后问题就变为，A和B一块报数，看谁先报到25了，进而变为20,15,10,5，当到5的时候，不管A怎么报数，最后一个数肯定是B报的，可以看出，作为后手的B在个游戏中是不会输的。

那么如果我们要报n个数，每次最少报一个，最多报m个，我们可以找到这么一个整数k和r，使n=k*（m+1）+r，代入上面的例子我们就可以知道，如果r=0，那么先手必败；否则，先手必胜。

 

巴什博奕：只有一堆n个物品，两个人轮流从中取物，规定每次最少取一个，最多取m个，最后取光者为胜。

代码如下：

    #include <iostream>
    using namespace std;
    int main()
    {
        int n,m;
        while(cin>>n>>m)
          if(n%(m+1)==0)  cout<<"后手必胜"<<endl;
          else cout<<"先手必胜"<<endl;
        return 0;
    }



 

例题有：HDU4764  Stone：

题目大意：Tang和Jiang轮流写数字，Tang先写，每次写的数x满足1<=x<=k，Jiang每次写的数y满足1<=y-x<=k，谁先写到不小于n的数算输。

结论：r=（n-1）%（k+1），r=0时Jiang胜，否则Tang胜。

 

 

二.  威佐夫博弈（Wythoff Game）：

有两堆各若干的物品，两人轮流从其中一堆取至少一件物品，至多不限，或从两堆中同时取相同件物品，规定最后取完者胜利。

直接说结论了，若两堆物品的初始值为（x，y），且x<y，则另z=y-x；

记w=（int）[（（sqrt（5）+1）/2）*z  ]；

若w=x，则先手必败，否则先手必胜。

代码如下：

    #include <cstdio>
    #include <cmath>
    #include <iostream>
    using namespace std;
    int main()
    {
        int n1,n2,temp;
        while(cin>>n1>>n2)
        {
            if(n1>n2)  swap(n1,n2);
            temp=floor((n2-n1)*(1+sqrt(5.0))/2.0);
            if(temp==n1) cout<<"后手必胜"<<endl;
            else cout<<"先手必胜"<<endl;
        }
        return 0;
    }


​     




三.  尼姆博弈（Nimm Game）：

尼姆博弈指的是这样一个博弈游戏：有任意堆物品，每堆物品的个数是任意的，双方轮流从中取物品，每一次只能从一堆物品中取部分或全部物品，最少取一件，取到最后一件物品的人获胜。

结论就是：把每堆物品数全部异或起来，如果得到的值为0，那么先手必败，否则先手必胜。

代码如下：

    #include <cstdio>
    #include <cmath>
    #include <iostream>
    using namespace std;
    int main()
    {
        int n,ans,temp;
        while(cin>>n)
        {
            temp=0;
            for(int i=0;i<n;i++)
            {
                cin>>ans;
                temp^=ans;
            }
            if(temp==0)  cout<<"后手必胜"<<endl;
            else cout<<"先手必胜"<<endl;
        }
        return 0;
    }


四.  斐波那契博弈：

有一堆物品，两人轮流取物品，先手最少取一个，至多无上限，但不能把物品取完，之后每次取的物品数不能超过上一次取的物品数的二倍且至少为一件，取走最后一件物品的人获胜。

结论是：先手胜当且仅当n不是斐波那契数（n为物品总数）

如HDU2516

    #include <iostream>  
    #include <string.h>  
    #include <stdio.h>  
    using namespace std;  
    const int N = 55;    
    int f[N];   
    void Init()  
    {  
        f[0] = f[1] = 1;  
        for(int i=2;i<N;i++)  
            f[i] = f[i-1] + f[i-2];  
    }    
    int main()  
    {  
        Init();  
        int n;  
        while(cin>>n)  
        {  
            if(n == 0) break;  
            bool flag = 0;  
            for(int i=0;i<N;i++)  
            {  
                if(f[i] == n)  
                {  
                    flag = 1;  
                    break;  
                }  
            }  
            if(flag) puts("Second win");  
            else     puts("First win");  
        }  
        return 0;  
    } 
