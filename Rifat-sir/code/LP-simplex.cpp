#include<iostream>
using namespace std;
void simplex(string *totalVar,int lenTotVar,string *basicVar,int lenBasVar,double **arr){

    while(true){
            //calculate pivot row and pivot column
        int pivColumn = -1;
        int pivRow = -1;
        double temp = 0;
        for(int i=0; i<lenTotVar; i++){
            if(arr[0][i]<temp) {
                temp = arr[0][i];
                pivColumn = i;
            }
        }
        if(pivColumn==-1) return;
        int check =1;
        double value;
        for(int i=1; i<lenBasVar; i++){
            if(arr[i][pivColumn]>0){
                if(check) {
                    temp = (0.0+arr[i][lenTotVar]) / arr[i][pivColumn];
                    check = 0;
                    pivRow = i;
                }
                else{
                        value = (0.0+arr[i][lenTotVar]) / arr[i][pivColumn];
                    if(value<temp){
                        temp = value;
                        pivRow = i;
                    }
                }
            }
        }
        if(pivRow ==-1) return;
        //finished calculating  pivot row and pivot column

        //elementary row operation
        double newPivRow,pivElement = arr[pivRow][pivColumn];
        basicVar[pivRow] = totalVar[pivColumn];
        for(int i=0; i<7; i++){
            if(i==pivColumn) continue;
            newPivRow = (0.0+arr[pivRow][i]) / pivElement;
            arr[pivRow][i] = newPivRow;

            for(int j=0; j<lenBasVar; j++){
                if(j==pivRow) continue;
                arr[j][i] -= arr[j][pivColumn] * newPivRow;

            }

            //finished elementary row operation
        }
        for(int i=0; i<lenBasVar; i++){
            if(i==pivRow) arr[pivRow][pivColumn] = 1;
            else arr[i][pivColumn] = 0;
        }

    }


}

int main(void){
    string toTalVar[] = {"z","x1","x2","s1","s2","s3"};
    string basicVar[] = {"z","s1","s2","s3"};
    int lenTotVar = 6,lenBasVar = 4;
    double **arr = new double*[lenBasVar];
    for(int i=0; i<lenBasVar; i++) arr[i] = new double[lenTotVar+1];

    double arr2[][7] = {1,-8,-9,0,0,0,0,0,2,3,1,0,0,50,0,2,6,0,1,0,80,0,3,3,0,0,1,70};
    for(int i=0; i<4; i++)
        for(int j=0; j<7; j++) arr[i][j] = arr2[i][j];

    simplex(toTalVar,lenTotVar,basicVar,lenBasVar,arr);

    cout<<arr[0][6]<<endl;

    return 0;
}
