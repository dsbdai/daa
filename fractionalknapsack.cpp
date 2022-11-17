#include<bits/stdc++.h>
using namespace std;

//create struct for storing profit and weight
struct item
{
    int profit,weight;

    item(int profit,int weight){
        this->profit=profit;
        this->weight=weight; 
    }
};

int cmppbyw(struct item x,struct item y){
    float r1=(float)x.profit/(float)x.weight; // (float) used to convert int value to float
    float r2=(float)y.profit/(float)y.weight;
    return r1>r2;
}

float fractionalKnapsackpbyw(int w,struct item a[],int n){
    sort(a,a+n,cmppbyw);

    
    float CurrentWeight=0;
    float TotalProfit=0;
    float RemainingWeight=0;

    for(int i=0;i<=n;i++){
        if(CurrentWeight + a[i].weight<=w){
            
            TotalProfit += a[i].profit;
            
            CurrentWeight += a[i].weight;
        }
        else{
            RemainingWeight=w-CurrentWeight;

            TotalProfit+=RemainingWeight*((float)a[i].profit/(float)a[i].weight);
            break;
        }
        
    }
    return TotalProfit;
}

float cmpbyweight(struct item x,struct item y){
    float r1=x.weight;
    float r2=y.weight;
    return r2>r1;
}

float fractionalKnapsackbyweight(int w,struct item a[],int n){
    sort(a,a+n,cmpbyweight);

    
    float CurrentWeight=0;
    float TotalProfit=0;
    float RemainingWeight=0;

    for(int i=0;i<=n;i++){
        if(CurrentWeight + a[i].weight<=w){
            
            TotalProfit += a[i].profit;
            
            CurrentWeight += a[i].weight;
        }
        else{
            RemainingWeight=w-CurrentWeight;

            TotalProfit+=RemainingWeight*((float)a[i].profit/(float)a[i].weight);
            break;
        }
        
    }
    return TotalProfit;
}
float cmpbyprofit(struct item x,struct item y){
    float r1=x.profit;
    float r2=y.profit;
    return r1>r2;
}

float fractionalKnapsackbyprofit(int w,struct item a[],int n){
    sort(a,a+n,cmpbyprofit);

    
    float CurrentWeight=0;
    float TotalProfit=0;
    float RemainingWeight=0;

    for(int i=0;i<=n;i++){
        if(CurrentWeight + a[i].weight<=w){
            
            TotalProfit += a[i].profit;
            
            CurrentWeight += a[i].weight;
        }
        else{
            RemainingWeight=w-CurrentWeight;

            TotalProfit+=RemainingWeight*((float)a[i].profit/(float)a[i].weight);
            break;
        }
        
    }
    return TotalProfit;
}

int main(){
    int w=25;
    item a[]={{24,24},{18,10},{18,10},{10,7}};

    int n=sizeof(a)/sizeof(a[0]);  

    cout<<fractionalKnapsackpbyw(w,a,n)<<endl;
    cout<<fractionalKnapsackbyweight(w,a,n)<<endl;
    cout<<fractionalKnapsackbyprofit(w,a,n)<<endl;
    
}
