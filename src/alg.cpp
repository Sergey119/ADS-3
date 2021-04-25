// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int property(char pr) {
if ((pr == '/')||(pr == '*')) {return 3;}
else if ((pr == '+')||(pr == '-')) {return 2;}
else if (pr == ')') {return 1;}
else if (pr == '(') {return 0;}
else return -1;
}

std::string infx2pstfx(std::string inf) {
TStack<char> inf1;
std::string inf2;
std::string inf3;
int i1 = 0;
int i2 = 0;
char temp1 = 0;
char temp2 = 0;
char temp3 = 0;
while (i1 < inf.size()-1){      
if (property(inf[i1]) == -1){
inf1.push(inf[i1]);
i1++;
} else if ((property(inf[i1]) == 3)||(property(inf[i1]) == 2)){
if (property(inf[i1+1]) != 0){
temp1 = inf[i1];
i1++;
} else {
if ((property(inf[i1-3]) == 1)&&(property(inf[i1-2]) == 3)){
temp3 = inf[i1];
i1++;
} else {
temp2 = inf[i1];
i1++;
}
}
} else if (property(inf[i1]) == 0){
i1++;
while (property(inf[i1]) != 1){
if (property(inf[i1]) == -1){
inf1.push(inf[i1]);
i1++;
} else if ((property(inf[i1]) == 3)||(property(inf[i1]) == 2)){
temp1 = inf[i1];
i1++;
}
}
if (property(inf[i1]) == 1){
inf1.push(temp1);
temp1 = 0;
i1++;
}
if (temp2 != 0){
inf1.push(temp2);
temp2 =0;
}
}
if ((temp1!= 0)&&(property(inf[i1]) == -1)){
inf1.push(inf[i1]);
inf1.push(temp1);
temp1 = 0;
i1++;
}
}
if (temp3 != 0){
inf1.push(temp3);
}
while (inf1.isEmpty() == false){
inf2 += inf1.get();
inf1.pop();
} 
i2 = inf2.size()-1;
while (i2 > -1){
inf3 += inf2[i2];
if (i2 > 0){
inf3 += ' ';
}
i2--;
} 
return inf3;
}

int eval(std::string pst) {
TStack<std::string> stack1;
int result = 0;    
std::string temp1;
int i2 = 0;
int k1;
int k2;
while (i2 <pst.size()){
if ((property(pst[i2]) == -1)&&(pst[i2+1] == ' ')){
temp1 = pst[i2];
stack1.push(temp1);
i2 += 2;
} else if((property(pst[i2]) == -1)&&(property(pst[i2+1]) == -1)){
temp1 = pst[i2]+pst[i2+1];
std::cout << temp1 << std::endl;
stack1.push(temp1); 
i2 +=2;
} else if(pst[i2] == '+'){
k1 = 0;
for (int i3 = 0; i3 < 2; i3++){
k1 += atoi(stack1.get().c_str());
stack1.pop();
}
temp1 = std::to_string(k1);
stack1.push(temp1);
i2 += 2;
} else if (pst[i2] == '-'){
k1 = 0;
k2 = 0;
k2 = atoi(stack1.get().c_str());
stack1.pop();
k1 = atoi(stack1.get().c_str());
stack1.pop();
k1 -= k2;
temp1 = std::to_string(k1);
stack1.push(temp1);
i2 += 2;
} else if (pst[i2] == '*'){
k1 = 1;
for (int i3 = 0; i3 < 2; i3++){
k1 *= atoi(stack1.get().c_str());
stack1.pop();
}
temp1 = std::to_string(k1);
stack1.push(temp1);
i2 += 2;
} else if(pst[i2] == '/'){
k1 = 0;
k2 = 0;
k2 = atoi(stack1.get().c_str());
stack1.pop();
k1 = atoi(stack1.get().c_str());
stack1.pop();
k1 /= k2;
temp1 = std::to_string(k1);
stack1.push(temp1);
i2 += 2;
}
}
result = atoi(stack1.get().c_str());
return result;
}
