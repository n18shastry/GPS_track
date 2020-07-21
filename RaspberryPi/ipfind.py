import ipinfo
from requests import get


access_token = 'API_KEY'
ip = get('https://api.ipify.org').text
print ('My public IP address is:', ip)
handler = ipinfo.getHandler(access_token)
details = handler.getDetails(ip)
loc= details.loc
print (loc)
