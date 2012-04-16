#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> getPrimes(int N)
{
bool * isPrime = new bool[N+1];
for(int i=0;i<=N;i++)
        isPrime[i] = false;

vector<int> primes;

int lt = sqrt(N);
if(lt*lt < N) lt++;

for(int x=1;x<=lt;x++)
	for(int y=1;y<=lt;y++)
		{
int t = 4*x*x + y*y;
if(t <=N && ( t%12==5  || t%12 ==1 ) )
		isPrime[t]^=true;

t-=x*x;
if(t<=N && t%12 == 7 )
	isPrime[t]^=true;


t-=2*y*y;
if(x > y && t<=N && t%12==11)
	isPrime[t]^=true;
		}	

for(int i=5;i<=lt;i++)
	if(isPrime[i])
		{
			int j = i*i;
			while(j<=N)
				{
					isPrime[j] = false;
					j*=i;
				}
		}
if(2<=N) primes.push_back(2);
if(3<=N) primes.push_back(3);
for(int i=5;i<=N;i++)
	if(isPrime[i]) primes.push_back(i);
return primes;
}

int main()
{
int N;
cout<<"Enter N to compute all primes from 2 to N :";
cin>>N;

vector<int> primes = getPrimes(N);
cout<<"There are "<<primes.size()<<" primes from 2 to N"<<endl;
cout<<" Primes :";
for(int i=0;i<primes.size();i++)
        cout<<" "<<primes[i];
cout<<endl;
return 0;
}
