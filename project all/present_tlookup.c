#include <stdio.h>
typedef unsigned long long uint64_t;

//Sbox
int sbox[16]={12,5,6,11,9,0,10,13,3,14,15,8,4,7,1,2};
uint64_t sbox1[16]={0x8000800000000000
,0x800000008000
,0x800080000000
,0x8000000080008000
,0x8000000000008000
,0x0
,0x8000000080000000
,0x8000800000008000
,0x80008000
,0x8000800080000000
,0x8000800080008000
,0x8000000000000000
,0x800000000000
,0x800080008000
,0x8000
,0x80000000
};
uint64_t sbox2[16]={0x4000400000000000
,0x400000004000
,0x400040000000
,0x4000000040004000
,0x4000000000004000
,0x0
,0x4000000040000000
,0x4000400000004000
,0x40004000
,0x4000400040000000
,0x4000400040004000
,0x4000000000000000
,0x400000000000
,0x400040004000
,0x4000
,0x40000000
};
uint64_t sbox3[16]={0x2000200000000000
,0x200000002000
,0x200020000000
,0x2000000020002000
,0x2000000000002000
,0x0
,0x2000000020000000
,0x2000200000002000
,0x20002000
,0x2000200020000000
,0x2000200020002000
,0x2000000000000000
,0x200000000000
,0x200020002000
,0x2000
,0x20000000
};
uint64_t sbox4[16]={0x1000100000000000
,0x100000001000
,0x100010000000
,0x1000000010001000
,0x1000000000001000
,0x0
,0x1000000010000000
,0x1000100000001000
,0x10001000
,0x1000100010000000
,0x1000100010001000
,0x1000000000000000
,0x100000000000
,0x100010001000
,0x1000
,0x10000000
};
uint64_t sbox5[16]={0x800080000000000
,0x80000000800
,0x80008000000
,0x800000008000800
,0x800000000000800
,0x0
,0x800000008000000
,0x800080000000800
,0x8000800
,0x800080008000000
,0x800080008000800
,0x800000000000000
,0x80000000000
,0x80008000800
,0x800
,0x8000000
};
uint64_t sbox6[16]={0x400040000000000
,0x40000000400
,0x40004000000
,0x400000004000400
,0x400000000000400
,0x0
,0x400000004000000
,0x400040000000400
,0x4000400
,0x400040004000000
,0x400040004000400
,0x400000000000000
,0x40000000000
,0x40004000400
,0x400
,0x4000000
};
uint64_t sbox7[16]={0x200020000000000
,0x20000000200
,0x20002000000
,0x200000002000200
,0x200000000000200
,0x0
,0x200000002000000
,0x200020000000200
,0x2000200
,0x200020002000000
,0x200020002000200
,0x200000000000000
,0x20000000000
,0x20002000200
,0x200
,0x2000000
};
uint64_t sbox8[16]={0x100010000000000
,0x10000000100
,0x10001000000
,0x100000001000100
,0x100000000000100
,0x0
,0x100000001000000
,0x100010000000100
,0x1000100
,0x100010001000000
,0x100010001000100
,0x100000000000000
,0x10000000000
,0x10001000100
,0x100
,0x1000000
};
uint64_t sbox9[16]={0x80008000000000
,0x8000000080
,0x8000800000
,0x80000000800080
,0x80000000000080
,0x0
,0x80000000800000
,0x80008000000080
,0x800080
,0x80008000800000
,0x80008000800080
,0x80000000000000
,0x8000000000
,0x8000800080
,0x80
,0x800000
};
uint64_t sbox10[16]={0x40004000000000
,0x4000000040
,0x4000400000
,0x40000000400040
,0x40000000000040
,0x0
,0x40000000400000
,0x40004000000040
,0x400040
,0x40004000400000
,0x40004000400040
,0x40000000000000
,0x4000000000
,0x4000400040
,0x40
,0x400000
};
uint64_t sbox11[16]={0x20002000000000
,0x2000000020
,0x2000200000
,0x20000000200020
,0x20000000000020
,0x0
,0x20000000200000
,0x20002000000020
,0x200020
,0x20002000200000
,0x20002000200020
,0x20000000000000
,0x2000000000
,0x2000200020
,0x20
,0x200000
};
uint64_t sbox12[16]={0x10001000000000
,0x1000000010
,0x1000100000
,0x10000000100010
,0x10000000000010
,0x0
,0x10000000100000
,0x10001000000010
,0x100010
,0x10001000100000
,0x10001000100010
,0x10000000000000
,0x1000000000
,0x1000100010
,0x10
,0x100000
};
uint64_t sbox13[16]={0x8000800000000
,0x800000008
,0x800080000
,0x8000000080008
,0x8000000000008
,0x0
,0x8000000080000
,0x8000800000008
,0x80008
,0x8000800080000
,0x8000800080008
,0x8000000000000
,0x800000000
,0x800080008
,0x8
,0x80000
};
uint64_t sbox14[16]={0x4000400000000
,0x400000004
,0x400040000
,0x4000000040004
,0x4000000000004
,0x0
,0x4000000040000
,0x4000400000004
,0x40004
,0x4000400040000
,0x4000400040004
,0x4000000000000
,0x400000000
,0x400040004
,0x4
,0x40000
};
uint64_t sbox15[16]={0x2000200000000
,0x200000002
,0x200020000
,0x2000000020002
,0x2000000000002
,0x0
,0x2000000020000
,0x2000200000002
,0x20002
,0x2000200020000
,0x2000200020002
,0x2000000000000
,0x200000000
,0x200020002
,0x2
,0x20000
};
uint64_t sbox16[16]={0x1000100000000
,0x100000001
,0x100010000
,0x1000000010001
,0x1000000000001
,0x0
,0x1000000010000
,0x1000100000001
,0x10001
,0x1000100010000
,0x1000100010001
,0x1000000000000
,0x100000000
,0x100010001
,0x1
,0x10000
};
int tout[64] = {0};

//generate rounds key
int* RoundKey(int *b2,int *k1)
{
    int temp,round_counter=1;
    //cout<<temp;
    for(int k=0;k<32;k++)
    {
       for(int i=63;i>=0;i--)
       {
          b2[k*64+i]=k1[i+16];
       }
        int k19[61]={0};
       for(int i=79;i>=19;i--)
       {
          k19[i-19]=k1[i];
       }
       for(int i=79;i>=0;i--)
       {
        if(i>60)
        k1[i]=k1[i-61];
        else
        k1[i]=k19[i];
       }
       int sb_in[4]={0};
       int sum=0,j=8,sum1;
       for(int i=3;i>=0;i--)
       {
         sum+=j*k1[76+i];
         j=j/2;
       }

       sum1=sbox[sum];
       for(int i=3;i>=0;i--)
       {
         k1[79-i]=sum1%2;
         sum1/=2;
       }
        temp=round_counter;
        for(int i=15;i<=19;i++)
        {
          if(temp%2)
          {
            k1[i] = k1[i]^(temp%2);
          }
          temp/=2;
       }
      round_counter++;
     }
     return b2;
}
//PRESENT Encryption function
int* Present_encrypt(int* plain, int* r_key)
{

   for(int i=1;i<=31;i++)
   {

      //add round key
      for(int j=63;j>=0;j--)
      {
         plain[j] = plain[j] ^ r_key[(i-1)*64+j];
      }
      //s-box

         int t1=0,t2=8,t3;
         int a1[64]={0};
         for(int k=63;k>=60;k--)
         {
           t1+=t2*(plain[k]%2);
           t2/=2;
         }
         t3=sbox1[t1];
         for(int k=0;k<64;k++)
         {
           a1[k]=t3%2; //use this instead table_out = sbox1[(data >> 60) & 0x0F]
           t3/=2;
           tout[k]=tout[k] ^ a1[k];
         }

         int t4=0,t5=8,t6;
         int a2[64]={0};
         for(int k=59;k>=56;k--) //use this instead table_out = sbox2[(data >> 56) & 0x0F]
         {
           t4+=t5*(plain[k]%2);
           t5/=2;
         }
         t6=sbox2[t4];
         for(int k=0;k<64;k++)
         {
           a2[k]=t6%2;
           t6/=2;
           tout[k]=tout[k] ^ a2[k];
         }

         int t7=0,t8=8,t9;
         int a3[64]={0};
         for(int k=55;k>=52;k--) //use this instead table_out = sbox3[(data >> 52) & 0x0F]
         {
           t7+=t8*(plain[k]%2);
           t8/=2;
         }
         t9=sbox3[t7];
         for(int k=0;k<64;k++)
         {
           a3[k]=t9%2;
           t9/=2;
           tout[k]=tout[k] ^ a3[k];
         }

         int t10=0,t11=8,t12;
         int a4[64]={0};
         for(int k=51;k>=48;k--) //use this instead table_out = sbox4[(data >> 48) & 0x0F]
         {
           t10+=t11*(plain[k]%2);
           t11/=2;
         }
         t12=sbox4[t10];
         for(int k=0;k<64;k++)
         {
           a4[k]=t12%2;
           t12/=2;
           tout[k]=tout[k] ^ a4[k];
         }

         int t13=0,t14=8,t15;
         int a5[64]={0};
         for(int k=47;k>=44;k--)
         {
           t13+=t14*(plain[k]%2);
           t14/=2;
         }
         t15=sbox5[t13];
         for(int k=0;k<64;k++)
         {
           a5[k]=t15%2;
           t15/=2;
           tout[k]=tout[k] ^ a5[k];
         }

         int t16=0,t17=8,t18;
         int a6[64]={0};
         for(int k=43;k>=40;k--)
         {
           t16+=t17*(plain[k]%2);
           t17/=2;
         }
         t18=sbox6[t16];
         for(int k=0;k<64;k++)
         {
           a6[k]=t18%2;
           t18/=2;
           tout[k]=tout[k] ^ a6[k];
         }

         int t19=0,t20=8,t21;
         int a7[64]={0};
         for(int k=39;k>=36;k--)
         {
           t19+=t20*(plain[k]%2);
           t20/=2;
         }
         t21=sbox7[t19];
         for(int k=0;k<64;k++)
         {
           a7[k]=t21%2;
           t21/=2;
           tout[k]=tout[k] ^ a7[k];
         }

         int t22=0,t23=8,t24;
         int a8[64]={0};
         for(int k=35;k>=32;k--)
         {
           t22+=t23*(plain[k]%2);
           t23/=2;
         }
         t24=sbox8[t22];
         for(int k=0;k<64;k++)
         {
           a8[k]=t24%2;
           t24/=2;
           tout[k]=tout[k] ^ a8[k];
         }

         int t25=0,t26=8,t27;
         int a9[64]={0};
         for(int k=31;k>=28;k--)
         {
           t25+=t26*(plain[k]%2);
           t26/=2;
         }
         t27=sbox9[t25];
         for(int k=0;k<64;k++)
         {
           a9[k]=t27%2;
           t27/=2;
           tout[k]=tout[k] ^ a9[k];
         }

         int t28=0,t29=8,t30;
         int a10[64]={0};
         for(int k=27;k>=24;k--)
         {
           t28+=t29*(plain[k]%2);
           t29/=2;
         }
         t30=sbox10[t28];
         for(int k=0;k<64;k++)
         {
           a10[k]=t30%2;
           t30/=2;
           tout[k]=tout[k] ^ a10[k];
         }

         int t31=0,t32=8,t33;
         int a11[64]={0};
         for(int k=23;k>=20;k--)
         {
           t31+=t32*(plain[k]%2);
           t32/=2;
         }
         t33=sbox11[t31];
         for(int k=0;k<64;k++)
         {
           a11[k]=t33%2;
           t33/=2;
           tout[k]=tout[k] ^ a11[k];
         }

         int t34=0,t35=8,t36;
         int a12[64]={0};
         for(int k=19;k>=16;k--)
         {
           t34+=t35*(plain[k]%2);
           t35/=2;
         }
         t36=sbox12[t34];
         for(int k=0;k<64;k++)
         {
           a12[k]=t36%2;
           t36/=2;
           tout[k]=tout[k] ^ a12[k];
         }

         int t37=0,t38=8,t39;
         int a13[64]={0};
         for(int k=15;k>=12;k--)
         {
           t37+=t38*(plain[k]%2);
           t38/=2;
         }
         t39=sbox13[t37];
         for(int k=0;k<64;k++)
         {
           a13[k]=t39%2;
           t39/=2;
           tout[k]=tout[k] ^ a13[k];
         }

         int t40=0,t41=8,t42;
         int a14[64]={0};
         for(int k=11;k>=8;k--)
         {
           t40+=t41*(plain[k]%2);
           t41/=2;
         }
         t42=sbox14[t40];
         for(int k=0;k<64;k++)
         {
           a14[k]=t42%2;
           t42/=2;
           tout[k]=tout[k] ^ a14[k];
         }

         int t43=0,t44=8,t45;
         int a15[64]={0};
         for(int k=7;k>=4;k--)
         {
           t43+=t44*(plain[k]%2);
           t44/=2;
         }
         t45=sbox15[t43];
         for(int k=0;k<64;k++)
         {
           a15[k]=t45%2;
           t45/=2;
           tout[k]=tout[k] ^ a15[k];
         }

         int t46=0,t47=8,t48;
         int a16[64]={0};
         for(int k=3;k>=0;k--)
         {
           t46+=t47*(plain[k]%2);
           t47/=2;
         }
         t48=sbox16[t46];
         for(int k=0;k<64;k++)
         {
           a16[k]=t48%2;
           t48/=2;
           tout[k]=tout[k] ^ a16[k];
         }
      }

    for(int j=0;j<64;j++)
    {
         plain[j] = tout[j] ^ r_key[31*64+j];
    }
     return plain;
}
//print Hexadecimal function
void PrintHex(unsigned char x)
{

 if(x%16<10) printf("%c",((x%16)+'0'));
 if(x%16>=10) printf("%c",((x%16-10)+'a'));
}

//Main function
int main() {
         char c1[100],c2[100];
         printf("Enter Key(only 20-digit hex): ");
         scanf("%s",c1);
         printf("Enter Plain Text: ");
         scanf("%s",c2);
         printf("--------------------------------------------------------------------------");
         int plain[64]={0};
         int key[80]={0};

         int l=79;
         for(int j=0;j<20;j++)
         {
          if(c1[j]=='0')
          {key[l]=0;key[l-1]=0;key[l-2]=0;key[l-3]=0;}
          else if(c1[j]=='1')
          {key[l]=0;key[l-1]=0;key[l-2]=0;key[l-3]=1;}
          else if(c1[j]=='2')
          {key[l]=0;key[l-1]=0;key[l-2]=1;key[l-3]=0;}
          else if(c1[j]=='3')
          {key[l]=0;key[l-1]=0;key[l-2]=1;key[l-3]=1;}
          else if(c1[j]=='4')
          {key[l]=0;key[l-1]=1;key[l-2]=0;key[l-3]=0;}
          else if(c1[j]=='5')
          {key[l]=0;key[l-1]=1;key[l-2]=0;key[l-3]=1;}
          else if(c1[j]=='6')
          {key[l]=0;key[l-1]=1;key[l-2]=1;key[l-3]=0;}
          else if(c1[j]=='7')
          {key[l]=0;key[l-1]=1;key[l-2]=1;key[l-3]=1;}
          else if(c1[j]=='8')
          {key[l]=1;key[l-1]=0;key[l-2]=0;key[l-3]=0;}
          else if(c1[j]=='9')
          {key[l]=1;key[l-1]=0;key[l-2]=0;key[l-3]=1;}
          else if(c1[j]=='a')
          {key[l]=1;key[l-1]=0;key[l-2]=1;key[l-3]=0;}
          else if(c1[j]=='b')
          {key[l]=1;key[l-1]=0;key[l-2]=1;key[l-3]=1;}
          else if(c1[j]=='c')
          {key[l]=1;key[l-1]=1;key[l-2]=0;key[l-3]=0;}
          else if(c1[j]=='d')
          {key[l]=1;key[l-1]=1;key[l-2]=0;key[l-3]=1;}
          else if(c1[j]=='e')
          {key[l]=1;key[l-1]=1;key[l-2]=1;key[l-3]=0;}
          else if(c1[j]=='f')
          {key[l]=1;key[l-1]=1;key[l-2]=1;key[l-3]=1;}
           l=l-4;
          }
         l=63;
         for(int j=0;j<16;j++)
         {
          if(c2[j]=='0')
          {plain[l]=0;plain[l-1]=0;plain[l-2]=0;plain[l-3]=0;}
          else if(c2[j]=='1')
          {plain[l]=0;plain[l-1]=0;plain[l-2]=0;plain[l-3]=1;}
          else if(c2[j]=='2')
          {plain[l]=0;plain[l-1]=0;plain[l-2]=1;plain[l-3]=0;}
          else if(c2[j]=='3')
          {plain[l]=0;plain[l-1]=0;plain[l-2]=1;plain[l-3]=1;}
          else if(c2[j]=='4')
          {plain[l]=0;plain[l-1]=1;plain[l-2]=0;plain[l-3]=0;}
          else if(c2[j]=='5')
          {plain[l]=0;plain[l-1]=1;plain[l-2]=0;plain[l-3]=1;}
          else if(c2[j]=='6')
          {plain[l]=0;plain[l-1]=1;plain[l-2]=1;plain[l-3]=0;}
          else if(c2[j]=='7')
          {plain[l]=0;plain[l-1]=1;plain[l-2]=1;plain[l-3]=1;}
          else if(c2[j]=='8')
          {plain[l]=1;plain[l-1]=0;plain[l-2]=0;plain[l-3]=0;}
          else if(c2[j]=='9')
          {plain[l]=1;plain[l-1]=0;plain[l-2]=0;plain[l-3]=1;}
          else if(c2[j]=='a')
          {plain[l]=1;plain[l-1]=0;plain[l-2]=1;plain[l-3]=0;}
          else if(c2[j]=='b')
          {plain[l]=1;plain[l-1]=0;plain[l-2]=1;plain[l-3]=1;}
          else if(c2[j]=='c')
          {plain[l]=1;plain[l-1]=1;plain[l-2]=0;plain[l-3]=0;}
          else if(c2[j]=='d')
          {plain[l]=1;plain[l-1]=1;plain[l-2]=0;plain[l-3]=1;}
          else if(c2[j]=='e')
          {plain[l]=1;plain[l-1]=1;plain[l-2]=1;plain[l-3]=0;}
          else if(c2[j]=='f')
          {plain[l]=1;plain[l-1]=1;plain[l-2]=1;plain[l-3]=1;}

           l=l-4;
        }

     printf("\nKey:          ");
     for(int i=0;i<20;i++){
        printf("%c",c1[i]);
     }
     printf("\n");

     int b2[2048]={0};
     int* b1=RoundKey(b2,key); //call RoundKey function

     printf("plain text:   ");
     for(int i=0;i<16;i++){
         printf("%c",c2[i]);
     }
     printf("\n");

     int* c=Present_encrypt(plain,b1);//call Present_encrypt function

     printf("Encrypt Text: ");
     for(int j=15;j>=0;j--)
     {
         int t1=0,t2=8,t3;
         for(int k=4*(j+1)-1;k>=4*j;k--)
         {
           t1+=t2*(c[k]%2);
           t2/=2;
         }
         PrintHex(t1);
     }
      printf("\n");

return 0;
}


