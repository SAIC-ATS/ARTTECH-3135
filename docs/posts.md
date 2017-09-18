---
layout: page
title: Posts
published: false
---

<ul class="list-unstyled">
    {% for post in site.posts %}
    {% assign author = site.data.people[post.author] %}
    <li>
        {{ post.date | date_to_string }} - {{ author.name }} :
        <a href="{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a>
        {% if page.tags %}
            <small><em>{{ post.tags | array_to_sentence_string }}</em></small>
        {% endif %}
    </li>
    {% endfor %}
</ul>
