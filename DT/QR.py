import qrcode

#create medic qr
qr = qrcode.QRCode(version=1,box_size=10,border=5)
qr.add_data("NAME: {test name} \nAGE: {test age}\nWCBs: 8bl/L\nNeutrophils: 62% \nLymphocytes: 28%\nMonocytes: 10%\nEosinophils 1%\nBasophils 0%\nRCBs: 3.84 tr/L\nHb: 11.7 g/dl\n")
qr.make(fit=True)

img = qr.make_image(fill='black',back_color='White')
img.save('/home/francisco/Documents/DT/doctor')

#create user qr

user = qrcode.QRCode(version=1,box_size=10,border=5)
user.add_data("Warning: Stress Level at 58% \nWarning: BPM at 118\nSugestion: Please consider using the 1/2 beathing exercise")
user.make(fit=True)

img = user.make_image(fill='black',back_color='White')
img.save('/home/francisco/Documents/DT/user')