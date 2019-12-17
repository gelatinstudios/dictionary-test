
struct Data {
        std::string country, region, type;
        std::string channel, priority, date;
        std::string order_date, ship_date;
        unsigned units_sold;
        double unit_price, unit_cost;
        double total_revenue, total_cost, total_profit;

};

std::ostream& operator<<(std::ostream& os, const Data& obj) {
        os << "Country: " << obj.country;
        return os;
}

struct Items {
        unsigned *keys;
        Data *data;
};

class Dictionary {
private:
        Items sales;
public:
        Dictionary() {
                sales.keys = new unsigned[1500000];
                sales.data = new Data[1500000];

                std::ifstream file("1500000 Sales Records.csv");
                std::string line;
                getline(file, line);
                for (size_t i = 0; getline(file, line); ++i) {
                        std::stringstream stream(line);

                        getline(stream, sales.data[i].region, ',');
                        getline(stream, sales.data[i].country, ',');
                        getline(stream, sales.data[i].type, ',');
                        getline(stream, sales.data[i].channel, ',');
                        getline(stream, sales.data[i].priority, ',');
                        getline(stream, sales.data[i].order_date, ',');

                        std::string token;
                        getline(stream, token, ',');
                        sales.keys[i] = stoul(token);
                        getline(stream, sales.data[i].ship_date, ',');
                        getline(stream, token, ',');
                        sales.data[i].units_sold = stoul(token);
                        getline(stream, token, ',');
                        sales.data[i].unit_price = stod(token);
                        getline(stream, token, ',');
                        sales.data[i].unit_cost = stod(token);
                        getline(stream, token, ',');
                        sales.data[i].total_revenue = stod(token);
                        getline(stream, token, ',');
                        sales.data[i].total_cost = stod(token);
                        getline(stream, token, ',');
                        sales.data[i].total_profit = stod(token);
                }

                file.close();
        }

        ~Dictionary() {
                delete[] sales.keys;
                delete[] sales.data;
        }

        Data *find(unsigned key) const {
                for (size_t i = 0; i < 1500000; ++i) {
                        if (sales.keys[i] == key) {
                                return &sales.data[i];
                        }
                }
                return nullptr;
        }

};
