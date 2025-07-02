#include <iostream>
#include <ranges>
#include <vector>
#include <chrono>


void print_date() {
    using namespace std::chrono;

    // Get current system time
    auto now = system_clock::now();

    // Extract calendar date
    auto today = floor<days>(now);
    year_month_day ymd{today};

    // Extract time of day
    auto time = now - today; // duration since midnight
    hh_mm_ss time_of_day{time};

    // Format and print: YYYY-MM-DD HH:MM:SS.mmm
    std::cout << std::format(
        "Current date and time: {:%Y-%m-%d} {:02}:{:02}:{:02}.{:03}\n",
        ymd,
        time_of_day.hours().count(),
        time_of_day.minutes().count(),
        time_of_day.seconds().count(),
        duration_cast<milliseconds>(time_of_day.subseconds()).count()
    );
}

void after_views_chunk() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7};

    // Chunk the data into sub-ranges of 3 elements each
    auto chunked = data | std::views::chunk(3);

    for (const auto& chunk : chunked) {
        std::cout << "[ ";
        for (int n : chunk) {
            std::cout << n << " ";
        }
        std::cout << "]" << std::endl;
    }
}

void before_views_chunk() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7};
    int chunkSize = 3;

    for (size_t i = 0; i < data.size(); i += chunkSize) {
        std::cout << "[ ";
        for (size_t j = i; j < i + chunkSize && j < data.size(); ++j) {
            std::cout << data[j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}

int main(int, char**) {
    print_date();

    std::cout << "after_views_chunk" << std::endl;
    auto start_1 = std::chrono::high_resolution_clock::now();
    {
        before_views_chunk();
    }
    auto end_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_1 = end_1 - start_1;
    std::cout << "before_views_chunk took " << duration_1 << " ms "<< std::endl;


    std::cout << "after_views_chunk" << std::endl;
    auto start_2 = std::chrono::high_resolution_clock::now();
    {
        after_views_chunk();
    }
    auto end_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_2 = end_2 - start_2;
    std::cout << "after_views_chunk took " << duration_2 << " ms "<< std::endl;
}
