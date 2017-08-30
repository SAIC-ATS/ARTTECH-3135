---
layout: page
title:  Notes
---

<ul class="list-unstyled">
    {% for post in site.categories.notes %}
    <li>
        {{ post.date | date_to_string }} :
        <a href="{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a>
    </li>
    {% endfor %}
</ul>
