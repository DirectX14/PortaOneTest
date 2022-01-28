#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isEven(int number){
    return (number % 2 == 0) ? true : false;
}

int main()
{
    string line,
           prevLine;
    vector<int> numbers;

    ofstream out;

    ifstream in("10m.txt");
    if(in.is_open()){
        int i = 0, j = 0;
        int min = 0,
            max = 0,
            all = 0,
            mediana = 0,
            que = 0;
        float average = 0;
        vector<int> inc_temp, inc;
        vector<int> dec_temp, dec;

        getline(in, prevLine);
        int curNum = stoi(prevLine);
        min = curNum;
        max = curNum;
        que = curNum;
        inc_temp.push_back(curNum);
        dec_temp.push_back(curNum);

        while(getline(in, line)){
            curNum = stoi(line);

            //get min
            if(curNum < min)
                min = curNum;

            //get max
            if(curNum > max)
                max = curNum;

            numbers.push_back(curNum);  //for mediana
            all += curNum;  //for average

            //increasing sequence
            if(inc_temp[i] < curNum){
                inc_temp.push_back(curNum);
                i++;
            }
            //save new sequence
            if(inc_temp.size() > inc.size()){
                inc = inc_temp;
            }

            //decreasing sequence
            if(dec_temp[j] > curNum){
                dec_temp.push_back(curNum);
                j++;
            }
            //save new sequence
            if(dec_temp.size() > dec.size()){
                dec = dec_temp;
            }

        }
        sort(numbers.begin(), numbers.end());

        //for(int x : numbers)
        //  cout << x << endl;
        //sort(numbers);

        //calculate mediana according to size
        if(isEven(numbers.size())){
            int pos1 = numbers.size() / 2,
                pos2 = (numbers.size() / 2) + 1;

            mediana = (0.5 * (numbers[pos1] + numbers[pos2]));
        } else {
            int pos1 = (numbers.size() / 2) + 1;
            mediana = numbers[pos1];
        }

        //calculate mid average
        average = all / numbers.size();

        cout << "min is " << min << endl;
        cout << "max is " << max << endl;
        cout << "mediana is " << mediana << endl;
        cout << "all is " << all << endl;
        cout << "average is " << average << endl;
        out.open("./result.txt");
        if (out.is_open()){
            out << "min is " << min << endl;
            out << "max is " << max << endl;
            out << "mediana is " << mediana << endl;
            out << "all is " << all << endl;
            out << "average is " << average << endl;

            cout << "increasing sequence: ";
            out << "increasing sequence: ";
            for(int num : inc){
                cout << num << " ";
                out << num << " ";
            }
            cout << endl;
            out << endl;
            cout << "decreasing sequence: ";
            out << "decreasing sequence: ";
            for(int num : dec){
                cout << num << " ";
                out << num << " ";
            }
            cout << endl;
            out << endl;
        };


    } else {
        cout << "Cannot open the file.";
    }
    in.close();

    cin.get();


    return 0;
}
