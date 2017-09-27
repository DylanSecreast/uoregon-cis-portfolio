import sys
import twitter

try:
	api = twitter.Api(
		consumer_key = 'F2CzqtWue9tvcHmmilectrCX7',
		consumer_secret = '5Byq1NiziCIed8eAobQyOdS3wNLYjOjVSJPbZ8wKMKPlajO0Ix',
		access_token_key = '838504742552662017-hF6vEuxlsIpEFVIsPv6lrQZhUhRIEFe',
		access_token_secret = 'AjbdO8DOrWLmOJVHohSoMAUmwL8ieKnY8ZUBQWDvW5O2Q'
	)
	status = api.PostUpdate("Hello World v2")
    # print "Successfully posted %s as %s" % (status.text, status.user.name)
except Exception:
	print "Error posting tweet"
