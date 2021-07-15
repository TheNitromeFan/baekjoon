import sys
import random


awards = ['대상', '장려상', 'QR 분해 상', '"Ghudegy Cup looks too intense for me" 상', 'QA 상', '결근상',
          'Re: 제로부터 시작하는 다이나믹 프로그래밍 상', 'You Need a Minecraft 상', 'UPWF 위원회 특별상', '직관주의자상']
prizes = ['치킨 기프티콘', '빵', '(도서) 4차 산업혁명은 없다', '(도서) Speedrun Science: A Long Guide To Short Playthroughs',
          '16GB USB', '레고 타워 브리지 - 10214', '바코드 스캐너', 'Katamari Damacy REROLL', 'Minecraft',
          'Roller Coaster Tycoon 2: Triple Thrill Pack']
winners = ['201812106', 'rubix', 'portableangel', 'sait2000', 'hyeonguk', 'greimul', 'dotorya', '2u_my_light',
           'namnamseo', 'cubelover', 'pichulia', 'xiaowuc1', 'zigui']


sys.stdout.write(random.choice(awards) + "\n")
sys.stdout.write(random.choice(prizes) + "\n")
sys.stdout.write(random.choice(winners) + "\n")
