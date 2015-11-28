#include <iostream>
#include <algorithm>

struct letter {
  int index, length;
  char *word;

  void set(int i, int l, char* w) {
    index = i;
    length = l;
    word = w;
  }
};

bool operator<(letter l1, letter l2) {
  int pos1 = l1.index, pos2 = l2.index, length = l1.length, gap = 1;
  char *word = l1.word;
  while(true) {
    if(std::max(pos1, pos2) >= length) {
      return pos1 > pos2;
    }
    if(word[pos1] != word[pos2]) {
      return word[pos1] < word[pos2];
    }
    pos1 += gap;
    pos2 += gap;
    gap *= 2;
  }
}

int* build_suffix_array(char* word, int length) { // works in O(n log^2 n), whereas an O(n) algorithm exists
  letter *temp = new letter[length];
  for (int i = 0; i < length; ++i) {
    temp[i].set(i, length, word);
  }
  std::sort(temp, temp + length);
  int *suffix_array = new int[length];
  for (int i = 0; i < length; ++i) {
    suffix_array[i] = temp[i].index;
  }
  return suffix_array;
}

int* build_lcp_array(char* word, int* suffix_array, int length) {
  int *lcp_array = new int[length], *suffix_inverse = new int[length];
  for(int i = 0; i < length; ++i) {
    suffix_inverse[suffix_array[i]] = i;
  }
  int k = 0;
  for(int i = 0; i < length; ++i) {
    if(suffix_inverse[i] == length - 1) {
      k = 0;
      continue;
    }
    int j = suffix_array[suffix_inverse[i] + 1];
    while((i + k < length) && (j + k < length) && (word[i + k] == word[j + k])) {
      ++k;
    }
    lcp_array[suffix_inverse[i]] = k;
    if(k != 0) --k;
  }
  return lcp_array;
}

int main() {
  int length;
  std::cin >> length;
  char *word = new char[length];
  for(int i = 0; i < length; ++i) {
    std::cin >> word[i];
  }
  int *suffix_array = new int[length];
  suffix_array = build_suffix_array(word, length);
  for (int i = 0; i < length; ++i) {
    std::cout << suffix_array[i] << ' ';
  }
  std::cout << '\n';
  int *lcp_array = new int[length];
  lcp_array = build_lcp_array(word, suffix_array, length);
  for (int i = 0; i < length; ++i) {
    std::cout << lcp_array[i] << ' ';
  }
  std::cout << '\n';
}