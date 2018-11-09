#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        printf("%s\n","Usage: ./caesar k");
        return 1;
    }
    int binarySearch(char arr[], int l, int r, int x);
    char arrc[26];
    char arrs[26];
    int k = atoi(argv[1]);
    for(int i=0;i<26;i++)
    {
        arrc[i]='A'+i;
        arrs[i]='a'+i;
    }
    string s = get_string("plaintext:  ");
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
            {
                int result = binarySearch(arrc, 0, 25, s[i]);
                int inc=(result+k)%26;
                s[i]=arrc[inc];
            }
            else
            {
                int result = binarySearch(arrs, 0, 25, s[i]);
                int inc=(result+k)%26;
                s[i]=arrs[inc];
            }
        }
    }
    printf("ciphertext: %s\n",s);

    return 0;
}
int binarySearch(char arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
   }

   // We reach here when element is not
   // present in array
   return -1;
}
