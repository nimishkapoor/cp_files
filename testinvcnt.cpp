#include <bits/stdc++.h>
using namespace std;
#define LL long long int
LL merge_array(LL a[],LL temp[],LL low,LL mid,LL high)
{
 LL i,j,k,count=0,p=mid-1;
 for(i=low;i<=high;i++)
 temp[i]=a[i];
 i=low;
 j=mid;
 k=low;
 while(i<=p && j<=high)
 {
  if(temp[i]<=temp[j])
  a[k++]=temp[i++];
  else
  {
   a[k++]=temp[j++];
   count+=(mid-i);
  }
 }
 while(i<=p)
 a[k++]=temp[i++];
 
 while(j<=high)
 a[k++]=temp[j++];
 
 return count;
}
LL merge_sort(LL a[],LL temp[],LL l,LL r)
{
 LL mid,count=0;
 if(l<r)
 {
  mid=(l+r)>>1;
 count=merge_sort(a,temp,l,mid);
 count+=merge_sort(a,temp,mid+1,r);
 count+=merge_array(a,temp,l,mid+1,r);
 }
 return count;
}
LL _merge_sort(LL a[],LL n)
{
 LL *temp=(LL *)malloc(sizeof(LL)*n);
 return merge_sort(a,temp,0,n-1);
}
int main() {
             LL t,n,i;      
             scanf("%lld",&t);
              while(t--)
              {
                  scanf("%lld",&n);
                   LL a[n];
                   for(i=0;i<n;i++)
                  scanf("%lld",&a[i]);
                  printf("%lld\n",_merge_sort(a,n));
                 }
 return 0;
}
