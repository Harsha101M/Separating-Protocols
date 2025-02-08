#include <bits/stdc++.h>

using namespace std;
//raw traffic file data
void createStruct(vector<vector<string>>& vec) {
  FILE* f = fopen("finalTraffic.txt", "r");
  char c;
  while ((c = getc(f)) != '\n')
    ;
  c = getc(f);
  while (c != EOF) {
    vector<string> curr;
    while (c == ' ' or c == '\t') {
      c = getc(f);
    }
    string d;
    while (c != ' ' and c != '\t') {
      d.push_back(c);
      c = getc(f);
    }
    curr.push_back(d);
    while (c == ' ' or c == '\t') {
      c = getc(f);
    }
    string time;
    while (c != ' ' and c != '\t') {
      time.push_back(c);
      c = getc(f);
    }

    curr.push_back(time);
    while (c == ' ' or c == '\t') {
      c = getc(f);
    }
    string source;
    while (c != ' ' and c != '\t') {
      source.push_back(c);
      c = getc(f);
    }
    curr.push_back(source);
    while (c == ' ' or c == '\t') {
      c = getc(f);
    }
    string destination;
    while (c != ' ' and c != '\t') {
      destination.push_back(c);
      c = getc(f);
    }
    curr.push_back(destination);
    while (c == ' ' or c == '\t') {
      c = getc(f);
    }
    string protocol;
    while (c != ' ' and c != '\t') {
      protocol.push_back(c);
      c = getc(f);
    }
    curr.push_back(protocol);
    while (c == ' ' or c == '\t') {
      c = getc(f);
    }
    string length;
    while (c != ' ' and c != '\t') {
      length.push_back(c);
      c = getc(f);
    }
    curr.push_back(length);
    vec.push_back(curr);
    while (c != '\n' and c != EOF) {
      c = getc(f);
    }
    if (c == EOF) {
      break;
    }
    c = getc(f);
  }
}
//Print the traffic file
void printStruct(vector<vector<string>> vec) {
  cout << endl;
  cout << "Number\t\tTime\t\t\tSource IP\t\tDestination IP\t\tProtocol\tLength\n";
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < 6; j++) {
      cout << vec[i][j] << "\t\t";
    }
    cout << endl;
  }
}
//Obtain ALP Filter
vector<vector<string>> filterALP(vector<vector<string>> vec, string s) {
  vector<vector<string>> next;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i][4] == s) {
      vector<string> curr;
      for (int j = 0; j < 6; j++) {
        curr.push_back(vec[i][j]);
      }
      next.push_back(curr);
    }
  }
  return next;
}
//Obtain IP filter
vector<vector<string>> filterIP(vector<vector<string>> vec, string source, string destination) {
  vector<vector<string>> next;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i][2] == source && vec[i][3] == destination) {
      vector<string> curr;
      for (int j = 0; j < 6; j++) {
        curr.push_back(vec[i][j]);
      }
      next.push_back(curr);
    }
  }
  return next;
}
//Obtain Size Filter
vector<vector<string>> filterSize(vector<vector<string>> vec, int start, int end) {
  vector<vector<string>> next;
  for (int i = 0; i < vec.size(); i++) {
    if (stoi(vec[i][5]) >= start && stoi(vec[i][5]) <= end) {
      vector<string> curr;
      for (int j = 0; j < 6; j++) {
        curr.push_back(vec[i][j]);
      }
      next.push_back(curr);
    }
  }
  return next;
}

int main() {
  vector<vector<string>> vec, curr;
  createStruct(vec);
  curr = vec;
  while (1) {
    cout << "---CHOOSE YOUR OPTION---" << endl;
    cout << "0.Exit \n1.Filter based on Application Layer Protocol\n2.Filter based on IP addresses\n3.Filter according to packet size\n4.Reset Filters\n";
    int choice;
    cin >> choice;
    cout << endl;
    if (choice == 0) {
      break;
    } else if (choice == 1) {
      cout << "Enter the Application Layer Protocol" << endl;
      string alp;
      cin >> alp;
      transform(alp.begin(), alp.end(), alp.begin(), ::toupper);
      curr = filterALP(curr, alp);
      printStruct(curr);
    } else if (choice == 2) {
      string source, destination;
      cout << "Enter the source and destination IP addresses" << endl;
      cin >> source >> destination;
      curr = filterIP(curr, source, destination);
      printStruct(curr);
    } else if (choice == 3) {
      int start, end;
      cout << "Enter the start and end limit for packet size" << endl;
      cin >> start >> end;
      curr = filterSize(curr, start, end);
      printStruct(curr);
    } else if (choice == 4) {
      curr = vec;
    } else {
      cout << "INVALID CHOICE" << endl;
      break;
    }
    cout << endl;
  }
}
