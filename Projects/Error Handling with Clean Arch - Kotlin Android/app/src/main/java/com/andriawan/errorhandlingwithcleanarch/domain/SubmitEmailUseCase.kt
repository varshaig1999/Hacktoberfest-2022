package com.andriawan.errorhandlingwithcleanarch.domain

import com.andriawan.errorhandlingwithcleanarch.R
import com.andriawan.errorhandlingwithcleanarch.data.MyRepositoryImpl
import com.andriawan.errorhandlingwithcleanarch.utils.Resource
import com.andriawan.errorhandlingwithcleanarch.utils.UiText

class SubmitEmailUseCase(
    private val repository: MyRepository = MyRepositoryImpl()
) {

    suspend fun execute(email: String): Resource<Unit> {
        if (email.notContains("@")) {
            return Resource.Error(UiText.StringResource(R.string.email_not_valid))
        }

        return repository.submitEmail(email)
    }

    // class InvalidEmailException: Exception("That is not a valid email")

    private fun String.notContains(regex: String): Boolean {
        return !this.contains(regex)
    }
}