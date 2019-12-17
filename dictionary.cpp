
//Region,Country,Item Type,Sales Channel,Order Priority,Order Date,Order ID,Ship Date,Units Sold,Unit Price,Unit Cost,Total Revenue,Total Cost,Total Profit

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

struct Item {
        unsigned key;
        Data data;
};

class Dictionary {
private:
        Item *sales;
public:
        Dictionary() {
                sales = new Item[1500000];
                std::ifstream file("1500000 Sales Records.csv");
                std::string line;
                getline(file, line);
                for (size_t i = 0; getline(file, line); ++i) {
                        std::stringstream stream(line);

                        getline(stream, sales[i].data.region, ',');
                        getline(stream, sales[i].data.country, ',');
                        getline(stream, sales[i].data.type, ',');
                        getline(stream, sales[i].data.channel, ',');
                        getline(stream, sales[i].data.priority, ',');
                        getline(stream, sales[i].data.order_date, ',');

                        std::string token;
                        getline(stream, token, ',');
                        sales[i].key = stoul(token);
                        getline(stream, sales[i].data.ship_date, ',');
                        getline(stream, token, ',');
                        sales[i].data.units_sold = stoul(token);
                        getline(stream, token, ',');
                        sales[i].data.unit_price = stod(token);
                        getline(stream, token, ',');
                        sales[i].data.unit_cost = stod(token);
                        getline(stream, token, ',');
                        sales[i].data.total_revenue = stod(token);
                        getline(stream, token, ',');
                        sales[i].data.total_cost = stod(token);
                        getline(stream, token, ',');
                        sales[i].data.total_profit = stod(token);
                }

                file.close();
        }

        ~Dictionary() {
                delete[] sales;
        }

        Data *find(unsigned key) const {
                for (size_t i = 0; i < 1500000; ++i) {
                        if (sales[i].key == key) {
                                return &sales[i].data;
                        }
                }
                return nullptr;
        }

};
