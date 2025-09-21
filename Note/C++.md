#### Comment
Use `/*` and `*/` for multi-line comments

#### Variables
`int`, `float`, `double`, `char`, `string`, `bool`
Note: `int` can store up to about 1e9, `long long` up to 1e18
Note: `float` has about six decimal digit accuracy, while `double` is about 15
Note: need  `#include <string>` to use `string`
Powers of ten:
```C++
// We can use "e" to represent the power of 10
int a = 5e6;
```

#### String
String concatenation:
```C++
string firstName = "John";  
string lastName = "Doe";  
string fullName = firstName + " " + lastName; // "John Doe"
```
String length:
```C++
string txt = "ABC"
cout<<txt.length();
```
Access:
```C++
string myString = "Hello";  
cout << myString[0];  // H
```
To create a string via a letter in a string, we need to change its type:
```C++
string str2 = string(1,str1[0]); //1 means one copy of the char
```
int to string
```C++
string s = to_string(1);
```
string to int
```C++
string s = "123456";
int i = stoi(s);
```
substr
- Single parameter: from that letter to the last
- Double parameter: from that letter, length
```C++
for (int j=0;j<=a.length();j++){
	newA.insert(a.substr(0,j)+s[i]+a.substr(j));
}
```
Finding an instance of a character
```C++
string s="ABCDE";
cout<<s.find('D'); //3
cout<<(s.find('X')==string::npos); //1 ie True
```

#### Cin
`cin` considers a space (whitespace, tabs, etc) as a terminating character
That's why, when working with strings, we often use the `getline()` function to read a line of text. It takes `cin` as the first parameter, and the string variable as second:
```C++
string fullName;  
cout << "Type your full name: ";  
getline (cin, fullName);  
cout << "Your name is: " << fullName;  
  
// Type your full name: John Doe  
// Your name is: John Doe
```

#### C++ math
`max(x,y)`、`min(x,y)`
```C++
cout << max(5, 10); // 10
cout << min(5, 10); // 5
```
Use the cmath library for more advanced funtions
```C++
#include <cmath>
cout << sqrt(64);  
cout << round(2.6); // rounds to the nearest integer
cout << log(2);
cout << pow(2,3);
cout << abs(-5);
```

#### Switch
```C++
int day = 4;  
switch (day) {  
  case 1:  
    cout << "Monday";  
    break;  
  case 2:  
    cout << "Tuesday";  
    break;  
  case 3:  
    cout << "Wednesday";  
    break;  
  case 4:  
    cout << "Thursday";  
    break;  
  case 5:  
    cout << "Friday";  
    break;
}  
// Outputs "Thursday" (day 4)
```

#### For-each loop
For-each loop can be used to loop throught elements in an array or other data structures
```C++
int myNumbers[5] = {10, 20, 30, 40, 50};  
for (int num : myNumbers) {  
  cout << num << "\n";  
}

string word = "Hello";  
for (char c : word) {  
  cout << c << "\n";  
}
```

#### Break & Continue
Continue skips an iteration, break breaks out of the loop entirely
```C++
for (int i = 0; i < 10; i++) {  
  if (i == 2) {  
    continue;  
  } 
  if (i == 5) {
    break;
  }
  cout << i << "\n";  
}
// 0 1 3 4
```

#### Function
Declaration
```C++
// **Function declaration**  
void myFunction(string fname) {  
  cout << fname << " Refsnes\n";  
}  
  
int main() {  
  myFunction("Liam");  
  return 0;  
}  
  
// Liam Refsnes  
```
If you want to change the value of a variable via a function, you have to pass the variable by reference:
```C++
void changeValue(int &num){
    num = 10;
}

int main(){
    int a = 5;
    changeValue(a);
    cout<<a;
    return 0;
}
// 10, if w/o the & symbol, 5
```

#### Vector
Vector is a resizable array
Remember to include:
```C++
#inlcude <vector>
```
Declaration & For-each loop & Access
```C++
// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Print vector elements  
for (string car : cars) {  
  cout << car << "\n";  
}

cout << cars[0]; // Volvo
```
Add & Remove vector element
```C++
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
cars.push_back("Tesla"); // Adds Tesla to the back of the vector
cars.pop_back(); // Removes the last element ie Tesla
```
Size
```C++
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
cout << cars.size();  // Outputs 4
```

#### Swap
```C++
swap(a,b);
```

#### Set
Set automatically deletes duplicates
```C++
set<string> S;
S.insert("Hi");
cout<<S.size();
cout<<S.count("Hi); //1
```

#### Bitset
```C++
#include <bitset>
bitset<10> B(3); // B is 10-bit, with the value of 3
cout<<B[0]; // outputs the rightmost digit of B, ie 1
```