#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    // std::cout << "prev_location: " << prev_location << std::endl;
    // std::cout << "next_location: " << next_location << std::endl;
    // // substr [,]
    // std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

void printVector(std::string name, std::vector<double> v) {
  if (name != "") {
    std::cout << name << ": ";
  }
  std::cout << "{";
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i];
    if (i < v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "}" << std::endl;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========

  printVector("x", x);
  printVector("w", w);

  int pad_size = w.size()/2;
  std::vector<double> padded(x.size() + 2 * pad_size);
  for (int i = 0; i < padded.size(); i++) {
    if (i < pad_size) {
      if (pack_with_zeros) {
        padded[i] = 0;
      } else {
        padded[i] = x[0];
      }
    } else if (i > padded.size() - 1 - pad_size) {
      if (pack_with_zeros) {
        padded[i] = 0;
      } else {
        padded[i] = x.back();
      }
    } else {
      padded[i] = x[i - pad_size];
    }
  }

  // printVector("padded", padded);

  for (int i = 0; i <= (padded.size() - w.size()); i++) {
    double val = 0;
    for (int j = 0; j < w.size(); j++) {
      val += padded[i + j] * w[j];
    }
    y.push_back(val);
  }

  printVector("y", y);

  // =========== END ===========

  return 0;
}

