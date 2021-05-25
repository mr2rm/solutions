from bs4 import BeautifulSoup


def process(name):
    html = open(name)
    soup = BeautifulSoup(html.read(), 'html.parser')
    return len(soup.find_all('a'))
