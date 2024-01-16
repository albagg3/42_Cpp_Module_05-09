/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/16 18:58:46 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
// #include "Data.hpp"

int	main()
{
	Data data;
	data.data_int = 42;
	
    uintptr_t serializedPtr = Serializer::serialize(&data);

    // Deserialize the pointer
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    // Check if deserialized pointer is equal to the original pointer
    if (deserializedPtr == &data) {
        std::cout << "Serialization and deserialization successful!\n";
        std::cout << "Original Data value: " << data.data_int<< "\n";
    } else {
        std::cout << "Serialization and deserialization failed!\n";
    }

    return 0;

}