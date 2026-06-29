#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float train[][2]={
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8}
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(){
    return (float)rand()/(float) RAND_MAX;
}

float cost(float w){
    float res=0.0;
    for(size_t i=0;i<train_count;++i){
        float x=train[i][0];
        float y=x*w;
        float d=y-train[i][1];
        res +=d*d;
        //printf("actual : %f vs expected : %f\n",y,train[i][1]);
    }
    res/=train_count;
    return res;
}

int main(){
    //srand(time(0));
    srand(69);
    float w=rand_float()*10;
    float eps=1e-3;
    float rate=1e-3;
    printf("initial:%f\n",cost(w));
    for(int i=0;i<1500;++i){
        float dcost=(cost(w+eps)-cost(w))/eps;
        w-=rate*dcost;
        //printf("iteration %d : %f\n",i+1,cost(w));
    }
    printf("final:%f\n",w);
    return 0;
}