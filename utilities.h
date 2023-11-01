#pragma once

#include <cmath>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>

/** 
 * Splits string into vector of strings using given delimiter
 * @param str A const string reference to be split into parts
 * @param delimiter Char value to use as delimiter
 * @return A vector of strings from str separated by delimiter
*/
std::vector<std::string> Split(const std::string& str, char delimiter);

/** 
 * Calculates distance between to locations in latitude and longitude
 * @param lat1 A long double of latitude value for first location
 * @param long1 A long double of longitude value for first location
 * @param lat2 A long double of latitude value for second location
 * @param long2 A long double of longitude value for second location
 * @return A long double of distance in Km or miles
*/
long double distance(long double lat1, long double long1, long double lat2, long double long2);

/** 
 * Converts degree into radians
 * @param degree A const long double to be converted
 * @return A long double value in radians
*/
long double toRadians(const long double degree);

/** 
 * @param s A vector to be reversed
 * @return A reversed vector of strings
*/
std::vector<std::string> reverse(std::vector<std::string> s);

/** 
 * @param matrix A vector to be reversed
 * Prints given matrix with equal column spacing
*/
void print_2d_vector(const std::vector<std::vector<double> > & matrix);

/** 
 * preforms matrix multiplication
 * @param l A 2D vector of double for left matrix
 * @param r A 2D vector of double for right matrix
 * @return A 2D vector of product of matrix multiplication
*/
std::vector<std::vector<double>> matrixMultiplication(const std::vector<std::vector<double>>& l, const std::vector<std::vector<double>>& r);