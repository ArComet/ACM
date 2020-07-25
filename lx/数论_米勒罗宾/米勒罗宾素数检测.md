- # 米勒罗宾素数检测（Miller-Rabin）                   

  ## 适用范围：较大数的较快素性判断

  ## 思路：

  因为有好的文章讲解具体原理（见参考文章），这里只是把代码的大致思路点一下，读完了文章如果还有些迷糊，可以参考以下解释

  原理是**费马小定理**：如果p是素数，则a^(p-1)%p==1，加上**二次探测定理**：如果p是一个素数，则x^2%p==1的解为，则x=1或者x=n-1。

  因为有通过费马小定理的伪素数的概率不是充分小，在此基础上加以改进判断。

  一次检测中：

  主要是把一个数n的n-1分解成d*2^r的形式，其中d为奇数，正向过程是a^n%p如果是1，就继续分解a^(n/2)%p，（a为一个与n互素的数）看是否为1,；如果是n-1就停止分解，说明至此无法判断是否为素数；如果不等于这两个值，则一定为合数。而在写代码过程是这个过程的逆向过程，先分解到底，看最后这个a^d%p是否为1或n-1，如果是说明已经分解到底了，也就是通过了此次素性测试。如果不是，说明在正向过程中出现了要么a的某次方为n-1，根据算法停止了检测过程；要么就是中间的某一个结果不等于这两个数，那么就是合数。就从最后往前面推，每一步看满不满足上述条件。直到判断为合数或者终止检测的那一步。

  多次检测过程：

  不停更换a测试。

  ## 代码：（代码中可能需要用到快速幂和大数乘积取余，可以参考前一篇博客）

  [![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

  ```
   1 #include <iostream>
   2 #include <time.h>
   3 using namespace std;
   4 long long an[] = {2,3,5,7,11,13,17,61};
   5 long long Random(long long n)//生成0到n之间的整数
   6 {
   7     return (double) rand()/RAND_MAX*n+0.5;//(doubel)rand()/RAND_MAX生成0-1之间的浮点数
   8 }
   9 long long q_mod(long long a,long long n,long long p)
  10 {
  11     a = a%p;
  12     //首先降a的规模
  13     long long sum = 1;//记录结果
  14     while(n)
  15     {
  16         if(n&1)
  17         {
  18             sum = (sum*a)%p;//n为奇数时单独拿出来乘
  19         }
  20         a = (a*a)%p;//合并a降n的规模
  21         n /= 2;
  22     }
  23     return sum;
  24 }
  25 long long q_mul(long long a,long long b,long long p)
  26 {
  27     long long sum = 0;
  28     while(b)
  29     {
  30         if(b&1)//如果b的二进制末尾是零
  31         {
  32             (sum += a)%=p;//a要加上取余
  33         }
  34         (a <<= 1)%=p;//不断把a乘2相当于提高位数
  35         b >>= 1;//把b右移
  36     }
  37     return sum;
  38 }
  39 bool witness(long long a,long long n)
  40 {
  41     long long d = n-1;
  42     long long r = 0;
  43     while(d%2==0)
  44     {
  45         d/=2;
  46         r++;
  47     }//n-1分解成d*2^r，d为奇数
  48     long long x = q_mod(a,d,n);
  49     //cout << "d " << d << " r " << r << " x " << x << endl;
  50     if(x==1||x==n-1)//最终的余数是1或n-1则可能是素数
  51     {
  52         return true;
  53     }
  54     while(r--)
  55     {
  56         x = q_mul(x,x,n);
  57         if(x==n-1)//考虑开始在不断地往下余的过程
  58         {
  59             return true;//中间如果有一个余数是n-1说明中断了此过程，则可能是素数
  60         }
  61     }
  62     return false;//否则如果中间没有中断但最后是余数又不是n-1和1说明一定不是素数
  63 }
  64 bool miller_rabin(long long n)
  65 {
  66     const int times = 50;//试验次数
  67     if(n==2)
  68     {
  69         return true;
  70     }
  71     if(n<2||n%2==0)
  72     {
  73         return false;
  74     }
  75     for(int i = 0;i<times;i++)
  76     {
  77         long long a = Random(n-2)+1;//1到(n-1)
  78         //cout << a << endl;
  79         if(!witness(a,n))
  80         {
  81             return false;
  82         }
  83     }
  84     return true;
  85 }
  86 int main()
  87 {
  88     long long num;
  89     cin >> num;
  90     if(miller_rabin(num))
  91     {
  92         cout << "Yes" << endl;
  93     }
  94     else
  95     {
  96         cout << "No" << endl;
  97     }
  98 }
  ```

  [![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

   

  ## 参考文章：

  Matrix67，数论部分第一节：素数与素性测试，http://www.matrix67.com/blog/archives/234（原理只推荐这一篇，这一篇是我目前见到的解释的最清晰，也可能是最精彩的，没有之一！虽然是07年的，好博客与时间没有关系）

  因为上篇代码部分用的是Pascal，这里找到c++的代码版本：

  StanleyClinton，素数判定Miller_Rabin算法详解，https://blog.csdn.net/maxichu/article/details/45458569

  还有rand函数的使用：https://jingyan.baidu.com/article/e73e26c060bdbc24adb6a7b0.html