#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <string>
#include <utility>
using namespace std;
void Rowdominance (vector < vector <short > > lastmap , bool Primearr[],bool Mintermsarr[],vector<string> Essential, vector<int>Minterms,vector<string>mostmin );
long long getbinary (int number){
    long long binnum=0;
if(number == 1){
    return 1;
}else if(number == 0){
return 0;}
else{
binnum = getbinary(number/2)*10 + number %2;
}

return binnum;
}
int howmanyones (long long number){    // LAZM A7WLO STRINGS MSH LONG LONG 3SHAN BIDRBB

        int counter=0;
        for(int i = 0 ; number!=0;i++){
            counter += number%10;
            number/=10;
        }
        return counter;
}
string ToString (long long binnum,int n){
    string str;
    for(int i = 0 ; i < n ; i++){
        if(binnum > 0){
            str.push_back(binnum%10 + (int)'0');
            binnum/=10;
        }else {
        str.push_back('0');}
    }
    return str;
}
int compare2Binary (string bin1,string bin2 , int n){
    int counter= 0 ;
    int location = -1;
for(int i = 0 ; i < n ; i++){
    if(bin1[i]!=bin2[i]){
        counter++;
        if(counter==1){
            location = i;
        }
    }
}
if(counter > 1){
    location = -1;
}
return location;
}
void PrimeImplicants (vector < pair < pair <  string , vector < int > > ,bool > > groups[],int n, vector <string> Essentials[],int numofenter,vector< vector < int > >covering[]){
    vector<pair < pair < string , vector<int> >, bool > >Secondary;
for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < (int)groups[i].size();j++){
            for(int k = 0 ; k < (int)groups[i+1].size();k++){
                if(compare2Binary(groups[i][j].first.first,groups[i+1][k].first.first,n)!= -1){
                    groups[i][j].second = true;
                    groups[i+1][k].second = true;
                                        //fadl el two flags array 3shan azbt elli fo2 w elli t7t
                    string stro = groups[i][j].first.first;
                    stro[compare2Binary(groups[i][j].first.first,groups[i+1][k].first.first,n)]='x';
                    pair < pair < string , vector<int> > , bool > p1;
                    p1.first.first = stro;
                    p1.second = false;
                    for(int u =0;u<(int)groups[i][j].first.second.size();u++){
                        p1.first.second.push_back(groups[i][j].first.second[u]);

                    }
                    for(int u =0;u<(int)groups[i+1][k].first.second.size();u++){
                        p1.first.second.push_back(groups[i+1][k].first.second[u]);
                       // cout << groups[i+1][k].first.second[u];
                    }
                    Secondary.push_back(p1);
                }
            }

    }for(int d = 0 ; d <(int) groups[i].size();d++){
    if(groups[i][d].second == false){
        Essentials[0].push_back(groups[i][d].first.first);
        vector<int>temp;
        for(int u = 0 ; u < (int)groups[i][d].first.second.size();u++){
            temp.push_back(groups[i][d].first.second[u]);

        }covering[0].push_back(temp); temp.clear();
    }
    }groups[i].clear();
    for(int d = 0 ; d <(int) Secondary.size();d++){
        groups[i].push_back(Secondary[d]);
    }Secondary.clear();
}
for(int i = 0 ; i < (int)groups[n-numofenter].size();i++){
    if(groups[n-numofenter][i].second == false){
        Essentials[0].push_back(groups[n-numofenter][i].first.first);
        vector<int > temp;
        for(int u = 0 ; u < (int)groups[n-numofenter][i].first.second.size();u++){
            temp.push_back(groups[n-numofenter][i].first.second[u]);
        }covering[0].push_back(temp);
        temp.clear();
    }
}
groups[n-numofenter].clear();
}
void TwoVectors(vector <string> Essential [], vector < vector <int> > covered[], int flag){
set <string> alter;
for(int i = 0 ; i <(int) Essential[0].size();i++){
    if(alter.count(Essential[0][i])==0){
        alter.insert(Essential[0][i]);
        Essential[1].push_back(Essential[0][i]);
        if(flag){
        covered[1].push_back(covered[0][i]);}
    }
}
}
string thenameofvar(string var){
    string tempp;
for(int i = 0 ; i <(int) var.size();i++){
if(var[var.size()-1-i]!= 'x'){
    if(var[var.size()-1-i]=='1'){
        tempp += (char)(i+(int)'A');

    }else{
        tempp += (char)(i+(int)'A');
        tempp += '\'';
    }
}
}
return tempp;
}
vector<string> SearchingforEssentials (int *flag,vector<vector <short > > Lastmap , vector <string>Essentials[],vector<int>Minterms, bool flagPrime[], bool flagMinterms[] ,int helpp ){
int counter=0;
int temp ,erasing;
erasing=0;
*flag = 0;
vector <string> MostEssen;
int sizeofPrime = Essentials[1].size();
for(int i = 0 ; i < (int)Minterms.size();i++){
    for(int j = 0 ; j < sizeofPrime && flagMinterms[i]!= false ;j++){
        if(!Lastmap[j].empty() && Lastmap[j][i]==1 && flagPrime[j]==true){
            counter++;
            temp = j;
        }
    }if(counter==1){MostEssen.push_back(Essentials[1][temp]);
                    *flag=1;
                    for(int u = 0 ; u < (int)Minterms.size();u++){
                        if(Lastmap[temp][u]==1 && !Lastmap[temp].empty()){
                                if(helpp==25){
                                    for(int q = 0 ; q<(int) Lastmap.size();q++){
                                        if(!Lastmap[q].empty()&&Lastmap[q][u]==1&&q!=temp){
                                            flagPrime[q]=false;
                                            Lastmap[q].clear();
                                        }
                                    }
                                }
                            flagMinterms[u]=false;
                        }
                    }

                    Lastmap[temp].clear();
                    flagPrime[temp]=false;
                    erasing++;
                    }counter=0;
}
return MostEssen;
}
bool checkTheBooleanList (bool lis[], int n ){
    bool flag=false;
for(int u = 0 ; u < n ; u++){
    if(lis[u]==true){
        flag = true;
    }
}
return flag ;
}
vector< bool  > ArrtoArr (bool list1[], int n1 ){
    vector< bool  > list2;
    for(int  i = 0 ; i < n1 ; i++){
        list2.push_back(list1[i]);
    }
    return list2;
}
int cost (vector<string > mostessen, string var ){
    set < char > inverters;
for(int i = 0 ;i < (int)mostessen.size();i++ ){
    for(int j = 0 ;j < (int)thenameofvar(mostessen[i]).size();j++){
        if(thenameofvar(mostessen[i])[j]=='\''){inverters.insert(thenameofvar(mostessen[i])[j-1]);}
    }
}int cost = 0;
for(int i = 0 ; i < (int)thenameofvar(var).size();i++){
    if(thenameofvar(var)[i]=='\''){if(inverters.count(thenameofvar(var)[i-1])==0){cost++;}}else{cost++;}
}return cost;
}
vector < pair < int , bool > > checkfortheprime (vector < pair < int ,  bool > > flagminterms ,int indexoftheprime , vector < vector < short > > lastmap){
for(int i = 0 ; i < (int)lastmap[indexoftheprime].size();i++ ){
    if(lastmap[indexoftheprime][i]==1){
        for(int u = 0 ; u < (int)flagminterms.size();u++){
            if(flagminterms[u].first == i ){flagminterms[u].second = false;}
        }
    }
}
return flagminterms;
}
vector<string> branching(vector < vector < short > >Lastmap , vector <string > Essentials[],vector<int>Minterms,bool flagPrime [], bool flagMinterms[], int help){
    int flag =1;
    vector <string > theRestOfTheExp;

while(flag){
        vector<string>tempp;
    tempp = SearchingforEssentials(&flag,Lastmap,Essentials,Minterms,flagPrime,flagMinterms,help);
if(flag){
    for(int u = 0 ; u <(int) tempp.size();u++){
        theRestOfTheExp.push_back(tempp[u]);

    }
}
}
return theRestOfTheExp;
}
void VectoArr(bool arr[],vector<bool>V){
for(int i = 0 ; i <(int) V.size();i++){
    arr[i]=V[i];
}}
vector <string> extrabranching(int index ,vector <int> Minterms ,vector < string > Essential [],vector < vector <short > > Lastmap , vector <bool > flagPrime , vector<bool> flagMinterms, vector <string>mostessen){
vector <string> lastround ;
lastround.push_back(Essential[1][index]);
bool Primearr[flagPrime.size()]; VectoArr(Primearr,flagPrime);
bool MintermsArr[flagMinterms.size()]; VectoArr(MintermsArr,flagMinterms);
for(int i = 0 ; i < (int)Lastmap[index].size(); i++){
    if(Lastmap[index][i]==1){
      //  removedcols.push_back(i);
      for(int j = 0 ; j < (int)Lastmap.size() ;j++){
        if(Lastmap[j][i]==1&& j!=index){Lastmap[j].clear();
        Primearr[j]=false;}}
        MintermsArr[i]=false;}
}
Lastmap[index].clear();
Primearr[index]=false;
vector<string>nextboom = branching(Lastmap,Essential,Minterms,Primearr,MintermsArr,25);
for(int i = 0 ;i <(int)nextboom.size();i++ ){
    lastround.push_back(nextboom[i]);
}
return lastround;

}
void Rowdominance (vector < vector <short > > lastmap , bool Primearr[],bool Mintermsarr[],vector<string> Essential, vector<int>Minterms,vector<string>mostmin ){
bool flag ;
vector<int > taken ;
for(int i = 0 ;i < (int)lastmap.size();i++){flag = true;
    for(int j = 0 ; j <(int) lastmap.size();j++){flag = true;

            if(j==i){continue;}
        for(int k = 0 ; k <(int) lastmap[i].size() && flag;k++){
            if(lastmap[j][k]>lastmap[i][k]){flag= false;}
        } if (flag == true ){
        if(cost(mostmin,Essential[i])<=cost(mostmin,Essential[j])){
            Primearr[j]=false;
        }
        }
    }
}

}
int virtualcheck(vector<string>patrick , vector<string > mostessen , bool mintermsf[],bool primes[],vector<string > Essential , vector<int>minterms,vector <vector <short > > Lastmap){
bool Mintermflag[minterms.size()],Primeflag[Essential.size()];
for(int i = 0 ;i <(int) minterms.size();i++){
        Mintermflag[i]=(mintermsf[i]);}
for(int i = 0 ;i <(int)Essential.size();i++ ){
    Primeflag[i]=(primes[i]);}
for(int i = 0 ; i <(int) patrick.size();i++ ){
    for(int l = 0 ;l <(int) Essential.size();l++ ){
        if(patrick[i]==Essential[l]){
            Primeflag[l]=false;
        }
    }
 }
 for(int i = 0 ;i <(int) Essential.size();i++){
    for(int c = 0 ; c < patrick.size();c++){
            if(Essential[i]==patrick[c]){
        for(int j =0 ; j<(int)minterms.size();j++){
            if(Lastmap[i][j]==1){
                Mintermflag[j]=false;
            }
        }}
    }
 }
    int flago= 0 ;
    for(int i = 0 ;i < (int)minterms.size();i++){
        if(Mintermflag[i]==true){
            flago++;
        }
    }
    return flago;
}
int main()
{
    //cout << "Hello world!" << endl;
    int n;
    cout << "would you please enter the number of variables ?";
    cin >>n;
    vector <int >Minterms;
    vector <int>Dontcare;
    set <int>Mintermss;
    int num;
    cout << "Please enter the minterms";
    cin >>num;
    while (num != -1){
        Minterms.push_back((int)(num ));
        Mintermss.insert((int)(num ));
        cin >> num;
    }
    cout << "Please enter the dont care terms";
    cin >> num;
     while (num != -1){
            if(Mintermss.count(num)==0){
        Dontcare.push_back((int)(num ));
        cin >> num;}else {
        cout << "ERROR";
        break;}
    }
vector < pair < pair < string , vector < int > > , bool > >  groups[n+1];
for(int i = 0 ; i < (int)Minterms.size();i++){
        string str44 = ToString(getbinary((int)Minterms[i]),n);
        pair < pair < string , vector < int > > , bool > p1;
        p1.first.first = str44;
        p1.first.second.push_back(Minterms[i]);
        p1.second = false;
    groups[howmanyones(getbinary((int)Minterms[i]))].push_back(p1);
}
for(int i = 0 ; i <(int) Dontcare.size();i++){
        string str44 = ToString(getbinary((int)Dontcare[i]),n);
        pair< pair < string , vector < int > > , bool > p1;
        p1.first.first = str44;
        p1.first.second.push_back(Dontcare[i]);
        p1.second = false;
    groups[howmanyones(getbinary((int)Dontcare[i]))].push_back(p1);
}
vector<string> Essentials[2];
vector< vector <int > > coveredmin[2];
int bomb = Essentials[0].size();
int c = 0;
while(c<n){

bomb = Essentials[0].size();
PrimeImplicants(groups,n,Essentials,c,coveredmin);
c++;
}
TwoVectors(Essentials,coveredmin,1);
cout << endl;
cout << "The Prime Implicant:" << endl;
for(int i = 0 ; i< (int)Essentials[1].size();i++){
     cout << thenameofvar(Essentials[1][i]);
     cout << ' ';

}
cout << endl ;
vector < vector < short > > Lastmap;//[Essentials[1].size()][Minterms.size()];
for(int i = 0 ; i < (int)Essentials[1].size();i++){
        vector <short > temp ;
    for(int j = 0 ; j <(int) Minterms.size();j++){
        temp.push_back(0);
    }
Lastmap.push_back(temp);
}
for(int i = 0 ; i < (int)Essentials[1].size();i++){
    for(int j = 0 ; j < (int)coveredmin[1][i].size();j++){
        for(int k = 0 ; k < (int)Minterms.size();k++){
            if(Minterms[k]==coveredmin[1][i][j]){
                Lastmap[i][k]=1;

            }
        }
    }
}
for(int i = 0 ; i <(int) Essentials[1].size();i++){cout << thenameofvar(Essentials[1][i]); cout << ' ';
    for(int j = 0 ; j < (int)Minterms.size();j++){
        cout << Lastmap[i][j] << ' ';
    } cout <<endl; cout << endl ;
}
bool flagMinterms [Minterms.size()];
bool flagPrime [Essentials[1].size()];
for(int u = 0 ; u < (int)Minterms.size();u++){
    flagMinterms[u]=true;
}
for(int u = 0 ; u < (int)Essentials[1].size();u++){
    flagPrime[u]=true;
}
vector < string > MostEssen[2];
int flag = 1 ;
MostEssen[0]=SearchingforEssentials(&flag,Lastmap,Essentials,Minterms,flagPrime,flagMinterms,1);
TwoVectors(MostEssen,coveredmin,0);
cout << "Essential Prime Implicants : " << endl;
    for(int i = 0 ; i < (int)MostEssen[1].size();i++){
        cout << thenameofvar(MostEssen[1][i]);
        cout << ' ';
    }
vector<string>theRestOfTheExp;
bool zeroflag=true;
vector<int>zeroprimes;
for(int i = 0 ; i <(int) Lastmap.size();i++){zeroflag=true;
    for(int u = 0; u <(int) Lastmap[i].size();u++){
      if(Lastmap[i][u]==1){zeroflag=false;
        }
    }if(zeroflag){zeroprimes.push_back(i);}
}
for(int i = 0; i < (int)zeroprimes.size();i++){
    flagPrime[zeroprimes[i]]=false;
}
Rowdominance(Lastmap,flagPrime,flagMinterms,Essentials[1],Minterms,MostEssen[1]);
//theRestOfTheExp=branching(Lastmap,Essentials,Minterms,flagPrime,flagMinterms,1);
vector < vector< string > > patrickexpres;
failed :
if(checkTheBooleanList(flagMinterms,Minterms.size())){
for(int i = 0 ; i < (int)Essentials[1].size();i++){
    if(flagPrime[i]==false){continue;}else{
            vector<  bool  > uncoveredMinterms = ArrtoArr(flagMinterms,Minterms.size());
            vector<  bool  > unusedPrimes = ArrtoArr(flagPrime,Essentials[1].size());
            vector<string>trial = extrabranching(i,Minterms,Essentials,Lastmap,unusedPrimes,uncoveredMinterms,MostEssen[1]);
            patrickexpres.push_back(trial);
            /*for(int u = 0 ; u < trial.size();u++){
                cout << thenameofvar(trial[u])<<' ';
            }cout <<endl;
            if(!virtualcheck(trial,MostEssen[1],flagMinterms,flagPrime,Essentials[1],Minterms,Lastmap)){
                cout << "yaaaaa";
            }*/
            }}}
int minn = 50000;
int j = 0;
cout <<endl;
if(!theRestOfTheExp.empty()){
    for(int i = 0 ;i < (int)theRestOfTheExp.size();i++){
        MostEssen[1].push_back(theRestOfTheExp[i]);
    }
}
vector <int > costt;
j=0;
int heyz=5000;
if(!patrickexpres.empty()){
    for(int i = 0 ; i <(int)patrickexpres.size();i++){costt.push_back(5000);
    if(virtualcheck(patrickexpres[i],MostEssen[1],flagMinterms,flagPrime,Essentials[1],Minterms,Lastmap)<=heyz){heyz =virtualcheck(patrickexpres[i],MostEssen[1],flagMinterms,flagPrime,Essentials[1],Minterms,Lastmap);
       costt[i]=0;
       for(int a = 0 ;a < costt.size();a++){
        if(virtualcheck(patrickexpres[i],MostEssen[1],flagMinterms,flagPrime,Essentials[1],Minterms,Lastmap)<virtualcheck(patrickexpres[a],MostEssen[1],flagMinterms,flagPrime,Essentials[1],Minterms,Lastmap)){
            costt[a]=5000;
        }
       }
        for(int j =0 ; j <(int) patrickexpres[i].size();j++){
            costt[i]+=cost(MostEssen[1],patrickexpres[i][j]);

        }}
    }

    for(int i = 0 ;i <(int)costt.size();i++ ){
        if(costt[i]< minn && costt[i]<5000 && !virtualcheck(patrickexpres[i],MostEssen[1],flagMinterms,flagPrime,Essentials[1],Minterms,Lastmap)){
            minn = costt[i]; j = i ;
        }
    }
    for(int i = 0 ;i <(int) patrickexpres[j].size();i++){
        MostEssen[1].push_back(patrickexpres[j][i]);
    }

 for(int i = 0 ; i <(int) patrickexpres[j].size();i++ ){
    for(int l = 0 ;l < (int)Essentials[1].size();l++ ){
        if(patrickexpres[j][i]==Essentials[1][l]){
            flagPrime[l]=false;
        }
    }
 }
 for(int i = 0 ;i <(int) Essentials[1].size();i++){
        for(int b = 0 ; b < patrickexpres[j].size();b++){


    if(Essentials[1][i]==patrickexpres[j][b]){
        for(int e =0 ; e<(int)Minterms.size();e++){
            if(Lastmap[i][e]==1){
                flagMinterms[e]=false;
            }
        }
    }}
 }}
cout << endl ;
cout << "The minimal Expression in SOP: ";
cout << endl;
//cout << MostEssen[1].size();
//for(int i = 0 ; i < MostEssen[1].size();i++){
  //  cout << thenameofvar(MostEssen[1][i])+ ' ';
//}cout << endl ;

if(checkTheBooleanList(flagMinterms,Minterms.size())){
   //cout << "shit ";
   cout << endl;
   int tmep;
   Rowdominance(Lastmap,flagPrime,flagMinterms,Essentials[1],Minterms,MostEssen[1]);
   patrickexpres.clear();
   if(checkTheBooleanList(flagMinterms,Minterms.size())){int calc=0; int position; int minimal = 5000; int posminimal;
      for(int o = 0 ; o < Minterms.size() ; o ++) {
      if(flagMinterms[o]==true){ calc++; position = o;}
      }if(calc==2 || calc == 1||1){
          for(int y = 0 ; y < Essentials[1].size();y++){
            if(Lastmap[y][position]==1){
                if(cost(MostEssen[1],Essentials[1][y])<minimal){
                    posminimal= y; minimal = cost(MostEssen[1],Essentials[1][y]);
                }
            }
          }
            MostEssen[1].push_back(Essentials[1][posminimal]);
            flagPrime[posminimal]=false;
            flagMinterms[position]=false;
      }
   else{
    goto failed;}}
    }
int totcost=0;
set<char > hey ;
for(int i = 0 ;i < (int)MostEssen[1].size();i++){
    for(int j = 0 ; j < (int)thenameofvar(MostEssen[1][i]).size();j++){
        if(thenameofvar(MostEssen[1][i])[j]!='\''){totcost++;}
        else {if(hey.count(thenameofvar(MostEssen[1][i])[j-1])==0)
            {totcost++; hey.insert(thenameofvar(MostEssen[1][i])[j-1]);}}
    } if(!(thenameofvar(MostEssen[1][i]).size()==2 && thenameofvar(MostEssen[1][i])[1]=='\'')){totcost++;}
    cout << thenameofvar(MostEssen[1][i]) + ' ';
}
if (MostEssen[1].size()==1){
    totcost--;
}
if(MostEssen[1].size()==1 && thenameofvar(MostEssen[1][0]).size()==1){
    totcost=0;
}
cout << endl ;
cout << "The min cost : ";
cout << totcost;
cout << endl ;
//if(checkTheBooleanList(flagMinterms,Minterms.size())){
   //cout << "shit ";
   //}


    return 0;
}

