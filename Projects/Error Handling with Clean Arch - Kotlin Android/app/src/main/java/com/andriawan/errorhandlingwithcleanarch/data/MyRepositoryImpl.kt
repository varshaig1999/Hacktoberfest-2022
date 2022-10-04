package com.andriawan.errorhandlingwithcleanarch.data

import com.andriawan.errorhandlingwithcleanarch.domain.MyRepository
import com.andriawan.errorhandlingwithcleanarch.utils.Resource
import com.andriawan.errorhandlingwithcleanarch.utils.UiText
import kotlinx.coroutines.delay
import kotlin.random.Random

class MyRepositoryImpl: MyRepository {

    override suspend fun submitEmail(email: String): Resource<Unit> {
        delay(500L)
        return if (Random.nextBoolean()) {
            Resource.Success(Unit)
        } else {
            if (Random.nextBoolean()) {
                Resource.Error(UiText.DynamicString("Server error"))
            } else {
                Resource.Error(UiText.DynamicString("Not authenticated error"))
            }
        }
    }
}