#include "SendAndReceive.h"

/// <summary>
/// GET�֐�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="url"></param>
/// <returns></returns>
template <class T>
pplx::task<T> Get(const std::wstring& url) {
	return pplx::create_task([=] {
		// �N���C�A���g�̐ݒ�
		http_client client(url);

		// ���N�G�X�g���M
		return client.request(methods::GET);
		})

		// �X�e�[�^�X�R�[�h����
			.then([](http_response response) {
			if (response.status_code() == status_codes::OK) {
				return response.extract_json();
			}
				});
}

/// <summary>
/// POST�֐�
/// </summary>
/// <param name="url"></param>
/// <param name="id"></param>
/// <returns></returns>
pplx::task<int> Post(const std::wstring& url) {
	return pplx::create_task([=] {
		// ���M�f�[�^�̍쐬
		json::value postData;
		postData[L"ID"] = json::value::string(L"");
		postData[L"score"] = json::value::string(L"");

		// �N���C�A���g�̐ݒ�
		http_client client(url);
		return client.request(methods::POST, L"", postData.serialize(), L"application/json");
		})

		// �X�e�[�^�X�R�[�h����
			.then([](http_response response) {
			if (response.status_code() == status_codes::OK) {
				return response.extract_json();
			}
				})

			// ���X�|���X
					.then([](json::value json) {
					return json[L"serverStatus"].as_integer();
						});
}