import multiprocessing

user      = 'www-data'
group     = 'www-data'
bind      = '0.0.0.0:80'
workers   = 2
threads   = workers
accesslog = '-'
errorlog = '-'
