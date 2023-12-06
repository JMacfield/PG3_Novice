#include "SendAndReceive.h"

/// <summary>
/// GET関数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="url"></param>
/// <returns></returns>
template <class T>
pplx::task<T> Get(const std::wstring& url) {
	return pplx::create_task([=] {
		// クライアントの設定
		http_client client(url);

		// リクエスト送信
		return client.request(methods::GET);
		})

		// ステータスコード判定
			.then([](http_response response) {
			if (response.status_code() == status_codes::OK) {
				return response.extract_json();
			}
				});
}

/// <summary>
/// POST関数
/// </summary>
/// <param name="url"></param>
/// <param name="id"></param>
/// <returns></returns>
pplx::task<int> Post(const std::wstring& url) {
	return pplx::create_task([=] {
		// 送信データの作成
		json::value postData;
		postData[L"ID"] = json::value::string(L"");
		postData[L"score"] = json::value::string(L"");

		// クライアントの設定
		http_client client(url);
		return client.request(methods::POST, L"", postData.serialize(), L"application/json");
		})

		// ステータスコード判定
			.then([](http_response response) {
			if (response.status_code() == status_codes::OK) {
				return response.extract_json();
			}
				})

			// レスポンス
					.then([](json::value json) {
					return json[L"serverStatus"].as_integer();
						});
}