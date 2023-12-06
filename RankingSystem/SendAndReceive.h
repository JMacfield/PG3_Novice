#pragma once

#include <cpprest/filestream.h>
#include <cpprest/http_client.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

/// <summary>
/// GETä÷êî
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="url"></param>
/// <returns></returns>
template <class T>
pplx::task<T> Get(const std::wstring& url);

/// <summary>
/// POSTä÷êî
/// </summary>
/// <param name="url"></param>
/// <param name="id"></param>
/// <returns></returns>
pplx::task<int> Post(const std::wstring& url);