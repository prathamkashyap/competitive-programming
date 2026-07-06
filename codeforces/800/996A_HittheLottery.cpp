#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int dollars = 0;
  cin >> dollars;

  int hundreds = 0;
  if (dollars >= 100) {
    hundreds = (dollars - (dollars%100))/100;
  
    dollars %= 100;
  }

  int twenties = 0;
  if (dollars >= 20) {
    twenties = (dollars - (dollars%20))/20;
  
    dollars %= 20;
  }

  int tens = 0;
  if (dollars >= 10) {
    tens = (dollars - (dollars%10))/10;
  
    dollars %= 10;
  }

  int fives = 0;
  if (dollars >= 5) {
    fives = (dollars - (dollars%5))/5;
  
    dollars %= 5;
  }

  cout << hundreds + twenties + tens + fives + dollars;
  return 0;
}