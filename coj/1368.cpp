# include <iostream>
# include <cmath>
# include <iomanip>
# include <algorithm>
typedef std::pair<size_t, size_t> coordinate;

double sqrt_(double x) {
    if (x <= 0)
        return 0;       // if negative number throw an exception?
    int exp = 0;
    x = frexp(x, &exp); // extract binary exponent from x
    if (exp & 1) {      // we want exponent to be even
        exp--;
        x *= 2;
    }
    double y = (1+x)/2; // first approximation
    double z = 0;
    while (y != z) {    // yes, we CAN compare doubles here!
        z = y;
        y = (y + x/y) / 2;
    }
    return ldexp(y, exp/2); // multiply answer by 2^(exp/2)
}

double distance(coordinate p1, coordinate p2)
{
	return sqrt_(((p1.first - p2.first) * (p1.first - p2.first)) + 
	((p1.second - p2.second) * (p1.second - p2.second)));
}

int main()
{
	size_t points_number, aux;
	std::cin >> points_number;
	coordinate points[points_number];
	unsigned int a_aux[points_number]; 
	for (size_t i = 0; i < points_number; ++i){
		std::cin >> aux;
		points[i].first = aux;
		std::cin >> aux;
		points[i].second = aux;
		a_aux[i] = i;
	}
	double final_distance = 0;
	for (size_t i = 0; i < points_number - 1; ++i)
    		final_distance += distance(points[a_aux[i]], points[a_aux[i + 1]]);
    double p_distance = 0;
  	while ( std::next_permutation(a_aux,a_aux+points_number)){
  		p_distance = 0;
    	for (size_t i = 0; i < points_number - 1; ++i){
    		p_distance += distance(points[a_aux[i]], points[a_aux[i + 1]]);
    		if (p_distance > final_distance)
    			break;
    	}
   
    	if (p_distance < final_distance)
    		final_distance = p_distance;
    		
  	}

	std::cout << std::fixed << std::setprecision(2) << final_distance;
	
	return 0;
}