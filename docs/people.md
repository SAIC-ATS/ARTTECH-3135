---
layout: page
title:  People
published: false
---

<ul>
{% for people_hash in site.data.people %}
{% assign person = people_hash[1] %}
  <li>
    {{ person.name }}
    <ul>
    {% assign hasPosts = false %}
    {% for post in site.posts %}
        {% if post.author == person.username %}
       	<li>
            {% assign hasPosts = true %}
        	{{ post.date | date_to_string }} : <a href="{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a>
    	</li>
		{% endif %}
    {% endfor %}
    {% if hasPosts == false %}
        <li>No posts yet.</li>
    {% endif %}
	</ul>
  </li>
{% endfor %}
</ul>
