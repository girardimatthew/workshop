#!/usr/bin/python

city_population = {
    'Tokyo': 13350000, # a key-value pair
    'Los Angeles': 18550000,
    'New York City': 8400000,
    'San Francisco': 1837442,
}

print city_population
print city_population['New York City']
print city_population['San Francisco']
city_population['San Francisco'] = 837442
print city_population['San Francisco']
print city_population.keys()

municipalities = {
    'New York City': [
        'Manhattan',
        'The Bronx',
        'Brooklyn',
        'Queens',
        'Staten Island'
    ],
    'Tokyo': [
        'Akihabara', 
        'Harajuku', 
        'Shimokitazawa', 
        'Nakameguro', 
        'Shibuya', 
        'Ebisu/Daikanyama', 
        'Shibuya District', 
        'Aoyama', 
        'Asakusa/Ueno', 
        'Bunkyo District', 
        'Ginza', 
        'Ikebukuro', 
        'Koto District', 
        'Meguro District', 
        'Minato District', 
        'Roppongi', 
        'Shinagawa District', 
        'Shinjuku', 
        'Shinjuku District', 
        'Sumida District', 
        'Tsukiji', 
        'Tsukishima']
}

print municipalities['New York City']
print municipalities['New York City'][0]