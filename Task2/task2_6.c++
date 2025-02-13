#include <iostream>
#include <cmath>

int main() {

    int words, lines, page;

    printf("Input count words, lines, page with space: ");
    std::cin >> words >> lines >> page;

    int half_words = floor(words/2);
    int third_line = floor(lines/3);
    int fith_page = floor(page/5);

    page = page - fith_page;
    lines = lines - third_line;

    std::cout << "Words count: " << third_line * half_words + lines * words;

    return 0;
}