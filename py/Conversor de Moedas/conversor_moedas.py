import requests

API_KEY = "api key"
base_url = f"https://v6.exchangerate-api.com/v6/{API_KEY}/latest/"

def converter(de, para, valor):
    url = base_url + de
    response = requests.get(url)
    if response.status_code != 200:
        print('Erro na API:', response.status_code)
        return None

    dados = response.json()
    if dados['result'] != 'success':
        print('Erro na resposta da API', dados.get('error-type', 'erro desconhecido'))
        return None

    taxa = dados['conversion_rates'].get(para)
    if taxa is None:
        print(f"Moeda '{para}' não encontrada.")
        return None
    return valor * taxa

print("\nConversor de Moedas")
print("Digite as siglas das moedas, por exemplo: BRL, USD, EUR...\n")

valor_desejado = float(input("| Valor: "))
moeda_atual = input("| Converter de: ").upper()
moeda_desejada = input("| Para: ").upper()

valor_convertido = converter(moeda_atual, moeda_desejada, valor_desejado)
if valor_convertido:
    print(f">>> {valor_desejado} {moeda_atual} equivale a {valor_convertido:.2f} {moeda_desejada}")
