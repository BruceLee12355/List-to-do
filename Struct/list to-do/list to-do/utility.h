#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include <cstddef>
#include <time.h>
#include <cstdint>
#include <cstring>
#include <iostream>

template <typename T>
T* copy(const T* array, size_t size) {
	T* copy_array = new T[size];

	for (size_t i = 0; i < size; ++i) {
		copy_array[i] = array[i];
	}

	return copy_array;
}

template <typename T>
T* reallocate(T* array, size_t size,
	size_t new_size
) {
	T* new_array = new T[new_size]{};
	size_t min_size = std::min(size, new_size);

	for (size_t i = 0; i < min_size; ++i) {
		new_array[i] = array[i];
	}

	delete[] array;

	return new_array;
}

template <typename T>
T* push_back(T* array, size_t size, T element) {
	array = reallocate(array, size, size + 1);
	array[size] = element;
	return array;
}

int* insert(
	int* array, size_t size,
	size_t index, int element
) {
	array = reallocate(array, size, size + 1);
	++size;
	for (size_t i = size; i > index; --i) {
		array[i] = array[i - 1];
	}
	array[index] = element;

	return array;
}


template <typename T>
T* pop(
	T* array, size_t size,
	size_t index, size_t count = 1
) {
	for (size_t i = index; i < size - count; ++i) {
		array[i] = array[i + count];
	}
	return reallocate(array, size, size - 1);
}

template <typename T>
bool has(T* array, size_t size, T element) {
	for (size_t i = 0; i < size; ++i) {
		if (array[i] == element)
			return true;
	}
	return false;
}

template <typename T>
int* remove_if(
	T* array, size_t& size,
	bool (*predicate)(T element)
) {
	for (size_t i = 0; i < size; ++i) {
		if (predicate(array[i])) {
			array = pop(array, size, i);
			i--;
			size--;
		}
	}

	return array;
}

template <typename T>
void print(T const* array, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

template <typename T>
void print(T const* const* array, size_t size_rows, size_t size_cols) {
	for (size_t i = 0; i < size_rows; i++) {
		print(array[i], size_cols);
	}
}

template <typename T>
void transform(
	T* array, size_t size,
	T(*transformator)(T element)
) {
	for (size_t i = 0; i < size; ++i) {
		array[i] = transformator(array[i]);
	}
}

template <typename T, typename ResultType>
ResultType accumulate(
	const T* array, size_t size,
	ResultType(*accumulator)(
		ResultType result, T element
		),
	ResultType initial
) {
	ResultType result = initial;

	for (size_t i = 0; i < size; ++i) {
		result = accumulator(result, array[i]);
	}

	return result;
}

struct DateTime {
	uint16_t year : 16;
	uint16_t month : 4;
	uint16_t day : 5;
	uint16_t hours : 5;
	uint16_t minutes : 6;
	uint16_t seconds : 6;
	static constexpr uint16_t days_per_months[12]{
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
};

DateTime getDateTime(const tm& tm_time) {
	return {
		(uint16_t)(tm_time.tm_year + 1900u),
		(uint16_t)(tm_time.tm_mon + 1u),
		(uint16_t)(tm_time.tm_mday),
		(uint16_t)(tm_time.tm_hour),
		(uint16_t)(tm_time.tm_min),
		(uint16_t)(tm_time.tm_sec)
	};
}

DateTime getCurrentTime() {
	time_t unix_time = time(NULL);
	tm gmtime;
	gmtime_s(&gmtime, &unix_time);
	return getDateTime(gmtime);
}

void print(const DateTime& dt) {
	std::cout
		<< (dt.day < 10 ? "0" : "")
		<< dt.day << '.'
		<< (dt.month < 10 ? "0" : "")
		<< dt.month << '.'
		<< dt.year << ' '
		<< (dt.hours < 10 ? "0" : "")
		<< dt.hours << ':'
		<< (dt.minutes < 10 ? "0" : "")
		<< dt.minutes << ':'
		<< (dt.seconds < 10 ? "0" : "")
		<< dt.seconds;
}

DateTime operator+(const DateTime& dt1, const DateTime& dt2) {
	DateTime result;
	uint16_t seconds = dt1.seconds + dt2.seconds;
	uint16_t minutes = dt1.minutes + dt2.minutes + seconds / 60;
	uint16_t hours = dt1.hours + dt2.hours + minutes / 60;
	uint16_t day = dt1.day + dt2.day + hours / 24;
	uint16_t month = dt1.month + dt2.month;
	// TODO: rework month limit reach
	if (day > DateTime::days_per_months[(month - 1) % 12]) {
		month += 1;
	}
	uint16_t year = dt1.year + dt2.year + month / 12;

	uint16_t previous_month = month%12 - 1;
	if (previous_month == 0)
		previous_month = 12;

	return {
		year,
		(uint16_t)(month % 12),
		(uint16_t)(day % DateTime::days_per_months[previous_month - 1]),
		(uint16_t)(hours % 24),
		(uint16_t)(minutes % 60),
		(uint16_t)(seconds % 60)
	};
}

#endif

