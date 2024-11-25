#include <stdio.h>
#include <list>
#include <iterator>

int main() {
    // 1970年の駅リスト
    std::list<const char*> stations1970 = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
        "Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
        "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
        "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
        "Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
        "Hamamatsucho", "Shimbashi", "Yurakucho"
    };

    // 2019年の駅リスト
    std::list<const char*> stations2019 = stations1970;
    auto it1970 = std::find(stations2019.begin(), stations2019.end(), "Nippori");
    if (it1970 != stations2019.end()) {
        stations2019.insert(std::next(it1970), "Nishi-Nippori");
    }

    // 2022年の駅リスト
    std::list<const char*> stations2022 = stations2019;
    auto it2019 = std::find(stations2022.begin(), stations2022.end(), "Shinagawa");
    if (it2019 != stations2022.end()) {
        stations2022.insert(std::next(it2019), "Takanawa Gateway");
    }

    // 駅名リストの表示関数
    auto displayStations = [](const std::list<const char*>& stations, const char* year) {
        printf("%s年の駅一覧:\n", year);
        for (const auto& station : stations) {
            printf("%s ", station);
        }
        printf("\n\n");
    };

    // 各年の駅リスト
    displayStations(stations1970, "1970");
    displayStations(stations2019, "2019");
    displayStations(stations2022, "2022");

    return 0;
}
