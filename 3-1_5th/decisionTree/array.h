#ifndef ARRAY_H
#define ARRAY_H
#include <bits/stdc++.h>
using namespace std;
class Array
{

private:
vector < vector < string > > Arr;
int responseIdx; // should actual index
public:
Array(string Data_File,int responseIdx)
{
  Arr.erase(Arr.begin(),Arr.end());
  ifstream Data(Data_File);
  string line,word;
  string item;
  vector < string > Row;
  while(!Data.eof())
    {
        getline(Data, line);
        istringstream iss(line);
        while (getline(iss, word, ',')) {

            // add all the column data
            // of a row to a vector
            Row.push_back(word);
        }
    /*
        while(iss >> item)
        {
            if (item.length())
            {
                Row.push_back(item);
            }
        }
    */
        if(line.length())
        {
            Arr.push_back(Row);
            Row.erase(Row.begin(),Row.end());
        }
    }
  Data.close();
  if(responseIdx<0 && responseIdx>=SizeX()){
    cout<<"response index error"<<endl;
  }
  else
    this->responseIdx = responseIdx;
}

Array(vector < vector < string > > newArr,int responseIdx)
{
  for(int i = 0; i < newArr.size(); i++)
    Arr.push_back(newArr[i]);

    if(responseIdx<0 && responseIdx>=SizeX()){
    cout<<"response index error"<<endl;
  }
  else
    this->responseIdx = responseIdx;
}

Array(){ };
~Array(){ };

string Element(int i,int j)
{
  return Arr[i][j];
}

int SizeX()
{
  return Arr[0].size();
}

int SizeY()
{
  return Arr.size();
}

vector < string > GetAttributes()
{
  vector < string > Attribute;
  int j;
  for(j = 0; j < SizeX(); j++)
  {
      Attribute.push_back(Arr[0][j]);
  }
  return Attribute;
}

map < string, vector < string > > GetAttributesUniqueValues()
{
  map < string, vector < string > > Attributes_Values;
  vector < string > Attribute_Values;
    int i, j;
    for(j = 0; j < Arr[0].size(); j++)
    {
        for(i = 1; i < Arr.size(); i++)
        {
            Attribute_Values.push_back(Arr[i][j]);
        }
        sort(Attribute_Values.begin(), Attribute_Values.end());
        Attribute_Values.erase(unique(Attribute_Values.begin(), Attribute_Values.end()), Attribute_Values.end());
        Attributes_Values[Arr[0][j]] = Attribute_Values;
    Attribute_Values.erase(Attribute_Values.begin(),Attribute_Values.end());
    }
  return Attributes_Values;
}

vector < string > GetAttributeUniqueValues(string The_Attribute)
{
  return GetAttributesUniqueValues()[The_Attribute];
}
vector < string > GetAttributeUniqueValues(int index)
{
  string The_Attribute = Arr[0][index];
  return GetAttributesUniqueValues()[The_Attribute];
}
vector < string > GetUniqueResponses()
{
  return GetAttributesUniqueValues()[Arr[0][responseIdx]];//[SizeX()-1]];
}

string getResponse(int row){
    return Arr[row][responseIdx];//[SizeX()-1]];
}

map<string,string> getRow(int index){
    map<string,string> row;
    for(int i=0;i<SizeX();i++) row[Arr[0][i]] = Arr[index][i];
    return row;
}

vector < vector < string > > Copy(vector<int> indexes){
    vector < vector < string > > result;
    result.push_back(GetAttributes());

    for(auto &i:indexes){
        if(i<1 && i>SizeY()) {
            cout<<"copy index error"<<endl;
            return result;
        }
        vector < string > row;
        for(int j=0;j<SizeX();j++)
            row.push_back(Arr[i][j]);

        result.push_back(row);
    }

    return result;
}



map < string, vector < string > > GetAttributeResponses(int index) //not unique
{
  map < string, vector < string > > myMap;
  for(int i=1;i<SizeY();i++){
    myMap[Arr[i][index]].push_back(Arr[i][responseIdx]);//[SizeX()-1]];
  }
  return myMap;
}

vector < string > GetAllResponses()
{
  vector < string > responses;
  for(int i = 1; i < SizeY(); i++)
  {
    responses.push_back(Arr[i][responseIdx]);//[Arr[0].size()-1]);
  }
  return responses;
}

string GetMajorResponse()
{
  vector < string > responses = GetAllResponses();
  map<string,int> myMap;
  for(auto &it:responses)
    myMap[it]++;
  int maxx = -1;
  string result;
  for(auto &it:myMap)
    if(maxx<it.second){
        maxx = it.second;
        result = it.first;
    }

    return result;

}
double ComputeEntropy(vector < string > responses)
{
  double entropy = 0;
  int total  = responses.size();
  map<string,int> myMap;
  for(auto &it:responses)
    myMap[it]++;

  for(auto &it:myMap){
    double pbablty = it.second/(total+0.0);
    entropy += -1*pbablty*log(pbablty)/log(2.0);
  }
  return entropy;
}

double responseEntropy(){
    return ComputeEntropy(GetAllResponses());
}

double attributeEntropy(int index){
    map < string, vector < string > > myMap = GetAttributeResponses(index);
    double entropy = 0;
    int total = GetAllResponses().size();
    for(auto &it:myMap)
        entropy += it.second.size()/(total+0.0) * ComputeEntropy(it.second);

    return entropy;
}
vector < string > skipCell(int i,int j){
    vector < string > row;
    for(int it=0;it<SizeX();it++)
        if(it!=j) row.push_back(Arr[i][it]);
    return row;

}
vector < vector < string > > compress(int index,string key){
    vector < vector < string > > tempArr;
    tempArr.push_back(skipCell(0,index));
    //cout<<"ok"<<endl;
    for(int i=1;i<SizeY();i++){
        if(Arr[i][index]==key)
            tempArr.push_back(skipCell(i,index));
    }
    return tempArr;
}
int nextResponseIdx(int skipAttIdx){
    if(skipAttIdx==responseIdx){
        cout<<"do not delete response attributes"<<endl;
        return 0;
    }
    else if(responseIdx<skipAttIdx) return responseIdx;
    else return responseIdx-1;
}

int getResponseIdx(){
    return responseIdx;
}

void Display()
{
  int i, j;
  for(i = 0; i < Arr.size(); i++)
  {
    for(j = 0; j < Arr[0].size(); j++)
    {
        cout << " " << Arr[i][j];
    }
    cout << endl;
  }
}


};

#endif // ARRAY_H
