#include<iostream>
#include<vector>
using namespace std;

vector<int> getPrimes(int N) /* Get all primes from 1 to N*/
{
bool * isPrime = new bool[N+1];
for(int i=0;i<=N;i++)
	isPrime[i] = true;

vector<int> primes;

int i=2;
	while(i<=N)
		{
		if(isPrime[i])
			{
			int j = 2*i;
			while(j<=N)
				{
					isPrime[j] = false;
					j+= i;
				} 
			primes.push_back(i);
			}
		i++;
		}
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
