#docker build -t "rsa" .
#docker run --name "rsa" -d -p 8004:8004 [IMAGE]

FROM ubuntu:16.04
	
RUN apt-get update && apt-get upgrade -y 
RUN apt-get install -y python3 socat build-essential

RUN adduser --disabled-password --gecos '' rsa
RUN chown -R root:rsa /home/rsa/
RUN chmod 750 /home/rsa
RUN chmod 740 /usr/bin/top
RUN chmod 740 /bin/ps
RUN chmod 740 /usr/bin/pgrep
RUN export TERM=xterm

WORKDIR /home/rsa/

COPY rsa.py /home/rsa

EXPOSE 8004

CMD su rsa -c "socat -T60 TCP-LISTEN:8004,reuseaddr,fork EXEC:/home/rsa/rsa.py"
