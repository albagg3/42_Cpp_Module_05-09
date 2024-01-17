/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/17 11:42:37 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int	main()
{
	Data data;
	data.data_int = 42;
	data.data_str = "hola";
	
    uintptr_t serializedPtr = Serializer::serialize(&data);
	
    // Deserialize the pointer
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    // Check if deserialized pointer is equal to the original pointer
    if (deserializedPtr == &data) {
        std::cout << "Serialization and deserialization successful!\n";
        std::cout << "Original Data int value: " << data.data_int<< "\n";
        std::cout << "Original Data str value: " << data.data_str<< "\n";
        std::cout << "We have created a data struct and casted it to serializedPtr: " << &data<< "\n";
        std::cout << "We have deserialized serializedPtr and the pointer is: " << deserializedPtr<< "\n";

    } else {
        std::cout << "Serialization and deserialization failed!\n";
    }

    return 0;
}