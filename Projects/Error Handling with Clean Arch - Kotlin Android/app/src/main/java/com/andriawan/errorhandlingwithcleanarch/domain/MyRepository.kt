package com.andriawan.errorhandlingwithcleanarch.domain

import com.andriawan.errorhandlingwithcleanarch.utils.Resource

interface MyRepository {
    suspend fun submitEmail(email: String): Resource<Unit>
}