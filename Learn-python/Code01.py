# 导入请求模块
# 安装该模块，可以用 pip install requests 命令

import requests

url = 'https://v3-web-prime.douyinvod.com/video/tos/cn/tos-cn-ve-15/o0EMgfiWDBvNFTOBfSEevAQM0CaIAuNAod75DA/?a=6383&br=619&bt=619&btag=c0000e00010000&cd=0%7C0%7C0%7C3&ch=5&cquery=100x_100z_100o_101s_100B&cr=3&cs=0&cv=1&dr=0&ds=3&dy_q=1728478159&expire=1728488987&feature_id=aa7df520beeae8e397df15f38df0454c&ft=p96FMRLaffPdhc~kN1zNvAq-antLjrKdS1UNRkapg0s1vjVhWL6&is_ssr=1&l=20241009204917098F9424BB7268193E6A&lr=all&mime_type=video_mp4&ply_type=4&policy=4&qs=0&rc=NmU6NGQ5NjxlaDVlZjpoNkBpamt2NW45cnlxdTMzNGkzM0BgLjFhLzEwX14xX2MtLjAyYSNfYWwtMmRzZGhgLS1kLWFzcw%3D%3D&signature=f41e1f74c220b72958621709941bf7b0&tk=webid&webid=cb4ecf3ff02a4bfca167d9a3131dd80189997eccc04d4a67a5889f5b70dc7531fe73b15020a9f57b86d2c04a46353654fdaf1f6e57d50b004bdea04eefe1467d1fd9a7f52c3fb2e5cec2688a9b62ad4efd7c294ed52c06154c02761fe789bdbc0e2493be708a4f274523726170e3f39046248e2b0bc29bfc24ab226d3e80cbec4c349f675cb7b79b2df142b7e97dfee6c7c994484238bd7fdaaa3f715db62cac-444b5f5d8079da66127af21da1323f13&fid=1aa11054ad26393e3b1ff6883d6fa996'

res = requests.get(url)
res.encoding = 'utf-8'
# res.status_code
# 响应码 200-成功 403-拒绝 404-丢失 500-错误
print(res.status_code)

# res.content # 响应的内容
# print(res.content)

open('视频1.mp4', 'wb').write(res.content)
